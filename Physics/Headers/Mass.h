#pragma once

// this class doesnt contain the actual mass of objects rather it tries to get a rough estimate of them 
// by taking the image and calculating its pixels then doing some maths on it to get it to be close

struct Mass
{
	unsigned char CalculateMass(sf::Sprite& sprite, std::string objectName);
};