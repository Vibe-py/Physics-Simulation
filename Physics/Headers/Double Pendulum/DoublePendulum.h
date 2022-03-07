#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Pendulum
{
public:
	Pendulum(int mass, float a0, int radius, int x, int y);
	Pendulum(int mass, float a0, int radius, Pendulum* upperPendulum);
	~Pendulum();
	void init(int mass, float a0, int radius);
	void Reset();
	void update();
	void draw(sf::RenderWindow& window);
	sf::Vector2f updatePos(float dt);
	sf::CircleShape getBody() { return *body; }
	sf::RectangleShape getArm() { return *arm; }
private:
	// void init(int mass, float a0, int radius);
	int getXPoint();
	int getYPoint();
	int mass, x, y, radius;
	//va is angular acceleration and v is angular velocity.
	float va, v, a;

	Pendulum* upperPendulum = nullptr;
	Pendulum* lowerPendulum = nullptr;
	sf::CircleShape* body;
	sf::RectangleShape* arm;
};