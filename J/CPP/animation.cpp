#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>
using namespace std;

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

class SpineDrawable : public sf::Drawable
{
    vector<sf::Shape *> nodes;
    float linkSize;

public:
    SpineDrawable()
    {
        linkSize = 50;
    }
    ~SpineDrawable()
    {
        int i, n;
        n = nodes.size();
        for (i = 0; i < n; i++)
        {
            delete nodes[i];
        }
    }
    void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        int i, n;
        n = nodes.size();
        for (i = 0; i < n; i++)
        {
            target.draw(*(nodes[i]), states);
        }
    }
    void addNode(sf::Shape *newNode)
    {
        int n;
        nodes.push_back(newNode);
        n = nodes.size();
        nodes[n - 1]->setPosition(1, 1);
        switch (n % 4)
        {
        case 0:
            nodes[n - 1]->setFillColor(sf::Color::Green);
            break;
        case 1:
            nodes[n - 1]->setFillColor(sf::Color::Yellow);
            break;
        case 2:
            nodes[n - 1]->setFillColor(sf::Color::Red);
            break;
        case 3:
            nodes[n - 1]->setFillColor(sf::Color::Blue);
            break;
        }
        if (n > 1)
        {
            nodes[n - 1]->setPosition(nodes[n - 2]->getPosition() - sf::Vector2f(linkSize, 0));
        }
    }
    void update(sf::Vector2f pos)
    {
        int i, n;
        sf::Vector2f newVector = (pos - nodes[0]->getPosition()) * 0.002f, aux;
        n = nodes.size();
        nodes[0]->setPosition(nodes[0]->getPosition() + newVector);
        // if (n > 1)
        // {

        //     newVector = (nodes[0]->getPosition() - nodes[1]->getPosition());
        //     setMagnitude(newVector, linkSize);
        //     nodes[1]->setPosition(nodes[0]->getPosition() - newVector);
        // }
        for (i = 1; i < n; i++)
        {
            newVector = (nodes[i - 1]->getPosition() - nodes[i]->getPosition());
            setMagnitude(newVector, linkSize);
            nodes[i]->setPosition(nodes[i - 1]->getPosition() - newVector);
        //     if (i % 3 == 1)
        //     {
        //         newVector = (nodes[i - 3]->getPosition() - nodes[i]->getPosition());
        //         setMagnitude(newVector, linkSize);
        //         nodes[i]->setPosition(nodes[i - 3]->getPosition() - newVector);
        //     }
        //     if (i % 3 == 2)
        //     {
        //         aux = (nodes[i - 2]->getPosition() - nodes[i - 1]->getPosition());
        //         setMagnitude(aux, linkSize);
        //         newVector.x = sqrtf(2.0) / 2.0 * (aux.x - aux.y);
        //         newVector.y = sqrtf(2.0) / 2.0 * (aux.x + aux.y);
        //         nodes[i]->setPosition(nodes[i - 2]->getPosition() - newVector);
        //     }
        //     if (i % 3 == 0)
        //     {
        //         aux = (nodes[i - 3]->getPosition() - nodes[i - 2]->getPosition());
        //         setMagnitude(aux, linkSize);
        //         newVector.x = sqrtf(2.0) / 2.0 * (aux.x + aux.y);
        //         newVector.y = sqrtf(2.0) / 2.0 * (-aux.x + aux.y);
        //         nodes[i]->setPosition(nodes[i - 3]->getPosition() - newVector);
        //     }
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snk");
    SpineDrawable s;
    sf::Vector2i cmp;
    float rx = 0.0, ry = 0.0, drx = 0.1, dry = 0.1;
    sf::Mouse head;
    srand(time(NULL));
    s.addNode(new sf::CircleShape(15));
    s.addNode(new sf::CircleShape(17.09));
    s.addNode(new sf::CircleShape(21.2));
    s.addNode(new sf::CircleShape(23.1));
    s.addNode(new sf::CircleShape(25));
    s.addNode(new sf::CircleShape(24.5));
    s.addNode(new sf::CircleShape(22.59));
    s.addNode(new sf::CircleShape(21.1));
    s.addNode(new sf::CircleShape(20.8));
    s.addNode(new sf::CircleShape(20.375));
    s.addNode(new sf::CircleShape(19.8));
    s.addNode(new sf::CircleShape(19.1));
    s.addNode(new sf::CircleShape(18.2));
    s.addNode(new sf::CircleShape(17));
    s.addNode(new sf::CircleShape(15));
    s.addNode(new sf::CircleShape(14.8));
    s.addNode(new sf::CircleShape(13.9));
    s.addNode(new sf::CircleShape(13));
    s.addNode(new sf::CircleShape(12.3));
    s.addNode(new sf::CircleShape(11.2));
    s.addNode(new sf::CircleShape(9));

    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));

    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));

    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));
    // s.addNode(new sf::CircleShape(5));

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
        if ((rx > 800) || (rx < 0))
            drx *= -1.0;
        if ((ry > 600) || (ry < 0))
            dry *= -1.0;
        window.clear();
        cmp = head.getPosition();
        if (((cmp.x > 800) || (cmp.x < 0)) || ((cmp.y > 600) || (cmp.y < 0)))
            s.update(sf::Vector2f(rx += (rand() % 10) * drx, ry += (rand() % 10) * dry));
        else
            s.update((sf::Vector2f)(cmp));
        window.draw(s);
        window.display();
    }

    return 0;
}