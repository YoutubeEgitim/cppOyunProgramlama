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

float Math::clamp(float val, float min, float max)
{
	float ret = val;
	if (val < min)
		ret = min;
	else if (val > max)
		ret = max;
	return ret;
}

bool Math::daireKareCarpisiyormu(const sf::Vector2f& daireMerkez, float yariCap, const sf::Vector2f& kareMerkez, float boyut)
{
	bool sonuc = false;
	float yariBoyut = boyut * 0.5f;

	sf::Vector2f farkVektor = daireMerkez - kareMerkez;

	float cX = Math::clamp(farkVektor.x, -yariBoyut, yariBoyut);

	float cY = Math::clamp(farkVektor.y, -yariBoyut, yariBoyut);

	sf::Vector2f carpisma = kareMerkez + sf::Vector2f(cX, cY);

	float mesafe = Math::length(daireMerkez - carpisma);

	if (mesafe <= yariCap)
	{
		sonuc = true;

	}
	return sonuc;
}
