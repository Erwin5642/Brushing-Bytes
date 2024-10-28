#ifndef ANDGATE_HPP
#define ANDGATE_HPP

#include "Component.hpp"

class AndGate : public Component
{
public:
    AndGate();
    void setPinA(const sf::Vector2f);
    void setPinB(const sf::Vector2f);
    void setPinOut(const sf::Vector2f);
    void setInputA(const bool value);
    void setInputB(const bool value);
    sf::Vector2f getPinA() const;
    sf::Vector2f getPinB() const;
    sf::Vector2f getPinOut() const;
    bool getOutput() const;
    void setState(const bool value);
    void getState(const bool value);
    void attachPinA(const sf::Vector2f pinA);
    void attachPinB(const sf::Vector2f pinB);
    sf::Vector2f getPinA() const;
    sf::Vector2f getPinB() const;
    sf::Vector2f getPinOut() const;
};

#endif