#ifndef ANDGATEDRAWABLE_HPP
#define ANDGATEDRAWABLE_HPP

#include "ComponentDrawable.hpp"

class AndGateDrawable : public ComponentDrawable{
    public: 
    void draw(sf::RenderTarget &target, sf::RenderStates states);
};

#endif