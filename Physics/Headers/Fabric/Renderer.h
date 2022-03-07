#pragma once

#include <unordered_map>

#include <SFML\Graphics.hpp>
#include "Engine\Physics\Physics.h"
#include "Engine\WindowContextHandler.h"

struct Renderer
{
    PhysicsSolver& solver;
    sf::VertexArray va;
    sf::Color color;

    explicit
        Renderer(PhysicsSolver& s)
        : solver(s)
        , va(sf::Lines)
        , color(sf::Color(255, 0, 0))
    {}

    void ChangeColor()
    {
        if (color.r == 255 && color.b == 0 && color.g == 0) { color.r = 0; color.b = 0; color.g = 0; return; }
        if (color.r == 0 && color.b == 0 && color.g == 0) { color.r = 0; color.b = 0; color.g = 255; return; }
        if (color.r == 0 && color.b == 0 && color.g == 255) { color.r = 0; color.b = 255; color.g = 0; return; }
        if (color.r == 0 && color.b == 255 && color.g == 0) { color.r = 255; color.b = 0; color.g = 0; return; }
    }

    void updateVA()
    {
        const uint32_t links_count = to<uint32_t>(solver.constraints.size());
        va.resize(2 * links_count);
        for (uint32_t i(0); i < links_count; ++i) {
            LinkConstraint& current_link = solver.constraints.data[i];
            va[2 * i].position = current_link.fParticle->position;
            va[2 * i + 1].position = current_link.sParticle->position;
            va[2 * i].color = color;
        }
    }

    void render(RenderContext& context)
    {
        updateVA();
        context.draw(va);
    }
};