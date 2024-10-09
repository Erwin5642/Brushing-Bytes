#include <SFML/Graphics.hpp>
using namespace std;

class Ball{
    public:
    sf::CircleShape circle;
    double dx, dy, x, y, r;
    Ball(double x, double y, double r){
        dx = dy = 1;
        this->x = x;
        this->y = y;
        this->r = r;
        circle = sf::CircleShape(r);
        circle.setFillColor(sf::Color::Yellow);
    }
    bool collides(){   
        bool flag = false;     
        if((dx * 0.1 + x + r > 800) || (dx * 0.1 + x < 0)){
            dx *= -1;
            flag = true;
        }
        if((dy * 0.1 + y + 2 * r > 600) || (dy * 0.1 + y < 0)){
            dy *= -1;
            flag = true;
        }
        return flag;
    }
    void update(){
        circle.setPosition(x, y);
        x += dx * 0.1;
        y += dy * 0.2;
    }
};

class BallManager{
    private:
    vector<Ball*> balls;
    public:
    ~BallManager(){
        vector<Ball*>::iterator it = balls.begin();
        while(it != balls.end()){
            delete *it;
            it++;
        }
    }
    void push_back(Ball *newBall){
        balls.push_back(newBall);
    }
    void divide(int i){
        double newRadius = balls[i]->r/2;
        balls[i]->circle.setRadius(newRadius);
        balls.push_back(new Ball(balls[i]->x, balls[i]->y, newRadius));
        balls[balls.size() - 1]->dx *= -1;
        balls[balls.size() - 1]->dy *= -1;
    }
    void drawBalls(sf::RenderWindow &window){
        int i, n = balls.size();
        for(i = 0; i < n; i++){
            window.draw((balls[i])->circle);
        }
    }
    void updateBalls(){
        int i, n = balls.size();
        for(i = 0; i < n; i++){
            balls[i]->update();
            if(balls[i]->collides()){
                if(balls.size() < 11){
                    divide(i);
                }
            }
        }
    }
};

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML exemplo");    
    BallManager balls;

    balls.push_back(new Ball(100, 100, 100));
    while(window.isOpen()){

        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        balls.updateBalls();
        balls.drawBalls(window);
        window.display();
    }

    return 0;
}