#pragma once

constexpr unsigned char cGravity = 9.8f;
constexpr unsigned char cScale = 4;
constexpr float cPi = 3.14159265358979f;

constexpr std::chrono::microseconds cFrameDur(16667);

struct Pos
{
	unsigned short x, y;

	Pos(unsigned short x, unsigned short y)
		:x(x), y(y)
	{
	}

	Pos(sf::Vector2i& pos)
		:x(pos.x), y(pos.y)
	{
	}
};