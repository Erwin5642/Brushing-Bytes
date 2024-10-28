#ifndef COMPONENTDRAWABLE_HPP
#define COMPONENTDRAWABLE_HPP

class Component;

class ComponentDrawable: public sf::Drawable{
    private:
    Component *gate;
    Shape *shape;
    char gateName[10];
    sf::Vector2f positionPinA;
    sf::Vector2f positionPinB;
    sf::Vector2f positionPinOut;

    public:
    ComponentDrawable(Component *gate, Shape *shape);
    virtual ~ComponentDrawable() = default;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};

#endif