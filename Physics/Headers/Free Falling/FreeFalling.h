#pragma once

class Window;

class FreeFalling
{
private:
	Mass massCalc;
	unsigned char mass;
	sf::Texture texture;
	sf::Sprite sprite;
	Pos position;

public:
	FreeFalling(std::string texturePath, Pos pos);
	void Draw(Window& window);
	void Fall();

public:
	Pos& getPos() { return position; }

public:
	void setPos(unsigned char x, unsigned char y) { position.x = x; position.y = y; }
	sf::Sprite& getSprite() { return sprite; }
}; 