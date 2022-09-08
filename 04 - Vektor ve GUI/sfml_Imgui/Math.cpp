#include "Math.hpp"

float Math::length(const sf::Vector2f& vec)
{
	return sqrtf(vec.x*vec.x+vec.y*vec.y);
}

float Math::dot(const sf::Vector2f& sol, const sf::Vector2f& sag)
{
	return sol.x*sag.x+sol.y*sag.y;
}

float Math::dotNormalize(const sf::Vector2f& sol, const sf::Vector2f& sag)
{
	return dot(normalize(sol),normalize(sag));
}

sf::Vector2f Math::normalize(const sf::Vector2f& vec)
{
	float l = length(vec);

	return sf::Vector2f(vec.x / l, vec.y / l);
}

float Math::radToDeg(float rad)
{
	return (rad*180.0f)/PI;
}

float Math::degToRad(float deg)
{
	return deg*PI/180.0f;
}
