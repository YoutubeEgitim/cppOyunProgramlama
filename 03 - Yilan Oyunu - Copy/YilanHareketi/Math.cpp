#include "Math.hpp"

const float M_PI = 3.141592653589793238462643383279502;
float dot(const sf::Vector2f& sol, const sf::Vector2f& sag)
{
	return sol.x * sag.x + sol.y * sag.y;
}
float uzunluk(const sf::Vector2f& vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}
sf::Vector2f normalize(const sf::Vector2f& vec)
{
	float boy = uzunluk(vec);
	return sf::Vector2f(vec.x / boy, vec.y / boy);

}
 float RadToDeg(float Rad)
{
	return (Rad * 180.0f) / M_PI;
}