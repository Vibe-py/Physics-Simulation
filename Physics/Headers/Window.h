#pragma once

class Window
{
private:
	sf::RenderWindow display;
	unsigned char width;
	unsigned char height;

public:
	Window(unsigned char width, unsigned char height);
	// void Render(std::vector<RenderAbles>& objectsInScence);
	void Render(const sf::Color& backgroundFill);

public: // getters
	sf::RenderWindow& getDisplay() { return display; }
	unsigned char getWidth() { return width; }
	unsigned char getHeight() { return height; }

private:
	// prevent copying
	Window(Window&) = delete;
	void operator=(Window&) = delete;
};