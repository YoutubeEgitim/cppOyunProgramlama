#pragma once
#include<SFML/Graphics.hpp>
namespace Math
{
	const float PI = 3.141592653589793238f;

	float length(const sf::Vector2f& vec);
	float dot(const sf::Vector2f& sol, const sf::Vector2f& sag);
	float dotNormalize(const sf::Vector2f& sol, const sf::Vector2f& sag);
	sf::Vector2f normalize(const sf::Vector2f& vec);
	float radToDeg(float rad);
	float degToRad(float deg);
	float clamp(float val, float min, float max);
	bool	daireKareCarpisiyormu(const sf::Vector2f& daireMerkez, float yariCap,
		const sf::Vector2f& kareMerkez, float boyut);

}