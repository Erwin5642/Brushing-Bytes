#include <SFML/System.hpp>
#include <cmath>
float getMagnitude(const sf::Vector2f &v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

void setMagnitude(sf::Vector2f &v, float magnitude)
{
    float scale = magnitude / getMagnitude(v);
    v.x *= scale;
    v.y *= scale;
}

float dotProduct(const sf::Vector2f &v1, const sf::Vector2f &v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}
