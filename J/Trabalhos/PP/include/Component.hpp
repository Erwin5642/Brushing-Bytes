#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component{
    public:
    virtual void setInputA(const bool value) = 0;
    virtual void setInputB(const bool value) = 0;
    virtual bool getOutput() const = 0;
    virtual void setPinA(const Vector2f) = 0;
    virtual void setPinB(const Vector2f) = 0;
    virtual void setPinOut(const Vector2f) = 0;
    virtual void setState(const bool value) = 0;
    virtual void getState(const bool value) = 0;
    virtual void attachPinA(const sf::Vector2f pinA) = 0;
    virtual void attachPinB(const sf::Vector2f pinB) = 0;
    virtual sf::Vector2f getPinA() const = 0;
    virtual sf::Vector2f getPinB() const = 0;
    virtual sf::Vector2f getPinOut() const = 0;
};

#endif
