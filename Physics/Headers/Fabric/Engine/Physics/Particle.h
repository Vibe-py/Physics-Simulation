#pragma once

#include <SFML\System\Vector2.hpp>
#include "..\Common\IndexVector.h"

struct Particle
{
	civ::ID			id =			0;
	float			mass =		 1.0f;
	bool			moving =	 true;
	sf::Vector2f	position;
	sf::Vector2f	oldPosition;
	sf::Vector2f	forces;
	sf::Vector2f	velocity;

    Particle() = default;

    explicit
        Particle(sf::Vector2f pos)
        : position(pos)
        , oldPosition(pos)
    {}

    void update(float dt)
    {
        if (!moving) return;
        oldPosition = position;
        velocity += (forces / mass) * dt;
        position += velocity * dt;
    }

    void updateDerivatives(float dt)
    {
        velocity = (position - oldPosition) / dt;
        forces = {};
    }

    void move(sf::Vector2f v)
    {
        if (!moving) return;
        position += v;
    }
};

using ParticleRef = civ::Ref<Particle>;