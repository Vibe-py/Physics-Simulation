#pragma once

#include <cstdint>
#include "Particle.h"
#include "..\Common\Math.h"

struct LinkConstraint
{
	civ::ID	id					 = 0;
	ParticleRef fParticle;
	ParticleRef sParticle;
	float distance =			1.0f;
	float strength =			1.0f;
	float maxElongationRatio =  1.5f;
	bool broken				 = false;

    LinkConstraint() = default;

    LinkConstraint(ParticleRef p_1, ParticleRef p_2)
        : fParticle(p_1)
        , sParticle(p_2)
    {
        distance = MathVec2::length(p_1->position - p_2->position);
    }

    [[nodiscard]]
    bool isValid() const
    {
        return sParticle && fParticle && !broken;
    }

    void solve()
    {
        if (!isValid()) { return; }
        Particle& p_1 = *fParticle;
        Particle& p_2 = *sParticle;
        const sf::Vector2f v = p_1.position - p_2.position;
        const float dist = MathVec2::length(v);
        if (dist > distance) {
            // Break if the distance is over the given threshold
            broken = dist > distance * maxElongationRatio;
            const sf::Vector2f n = v / dist;
            const float c = distance - dist;
            const sf::Vector2f p = -(c * strength) / (p_1.mass + p_2.mass) * n;
            // Apply position correction
            p_1.move(-p / p_1.mass);
            p_2.move(p / p_2.mass);
        }
    }
};