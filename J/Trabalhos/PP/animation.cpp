#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>
using namespace std;

float getMagnitude(const sf::Vector2f &v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

void setMagnitude(sf::Vector2f &v, float magnitude){
    float scale = magnitude/getMagnitude(v);
    v.x *= scale;
    v.y *= scale;
}

float dotProduct(const sf::Vector2f &v1, const sf::Vector2f &v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

class SpineDrawable : public sf::Drawable{
    vector<sf::CircleShape*> nodes;
    vector<double> angles;
    float linkSize;
    public:
    SpineDrawable(){
        linkSize = 25;
    }
    ~SpineDrawable(){
        int i, n;
        n = nodes.size();
        for(i = 0; i < n; i++){
            delete nodes[i];
        }
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        int i, n;
        n = nodes.size();
        for(i = 0; i < n; i++){
            target.draw(*(nodes[i]), states);
        }
    }
    void addNode(sf::CircleShape *newNode){
        int n;
        nodes.push_back(newNode);
        n = nodes.size();
        nodes[n - 1]->setPosition(1, 1);
        if(n > 1){
            nodes[n - 1]->setPosition(nodes[n-2]->getPosition() - sf::Vector2f(linkSize, 0));
            angles.push_back(0);
        }
    }
    void update(sf::Vector2f pos){
        int i, n;
        sf::Vector2f newVector = (pos - nodes[0]->getPosition()) * 0.1f;
        n = nodes.size();
        nodes[0]->setPosition(nodes[0]->getPosition() + newVector);
        for(i = 1; i < n; i++){
            newVector = (nodes[i - 1]->getPosition() - nodes[i]->getPosition());
            setMagnitude(newVector, linkSize);
            nodes[i]->setPosition(nodes[i - 1]->getPosition() - newVector);
        }
    };
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snk");
    SpineDrawable s;
    sf::Mouse head; 
    s.addNode(new sf::CircleShape(20));
    s.addNode(new sf::CircleShape(21.25));
    s.addNode(new sf::CircleShape(22.50));
    s.addNode(new sf::CircleShape(23.75));
    s.addNode(new sf::CircleShape(25));
    s.addNode(new sf::CircleShape(22));
    s.addNode(new sf::CircleShape(20));
    s.addNode(new sf::CircleShape(17));
    s.addNode(new sf::CircleShape(15));
    s.addNode(new sf::CircleShape(13));
    s.addNode(new sf::CircleShape(11));
    s.addNode(new sf::CircleShape(9));
    s.addNode(new sf::CircleShape(7));
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        s.update((sf::Vector2f)(head.getPosition()));
        window.draw(s);
        window.display();
    }

    return 0;
}