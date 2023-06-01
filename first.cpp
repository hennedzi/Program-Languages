//составить программу с использованием классов для реализации «бегущей» точки из левого верхнего угла экрана в нижний правый угол экрана по строкам;
//цвет точки выбирается произвольно;
//продемонстрировать работу двух конструкторов: обычного конструктора и конструктора по умолчанию.

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class RunningPoint {
private:
   sf::CircleShape shape;
   float x, y;
   float speed;
public:
   RunningPoint(float startX, float startY, float startSpeed, sf::Color color)
           : x(startX), y(startY), speed(startSpeed)
   {
       shape.setFillColor(color);
       shape.setRadius(10);
       shape.setOrigin(10, 10);
       shape.setPosition(x, y);
   }
   RunningPoint() : RunningPoint(0, 0, 1, sf::Color::Green)
   {
   }
   void move()
   {
       x += speed;
       if (x > 800) {
           x = 0;
           y += 50;
       }
       if (y > 600) {
           y = 0;
       }
       shape.setPosition(x, y);
   }
   sf::CircleShape getShape()
   {
       return shape;
   }
};
int main()
{
   sf::RenderWindow window(sf::VideoMode(800, 600), "Running Point");
   window.setFramerateLimit(60);


   RunningPoint point(0, 0, 3, sf::Color::Red);
   RunningPoint point2;


   while (window.isOpen()) {
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed) {
               window.close();
           }
       }
       window.clear(sf::Color::White);
       point.move();
       point2.move();
       window.draw(point.getShape());
       window.draw(point2.getShape());
       window.display();
   }


   return 0;
}
