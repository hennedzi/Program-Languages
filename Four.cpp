/*Напишите программу создания базового класса num.
  В этом классе должно храниться целое и определена виртуальная функция shownum( ). 
  Создайте два производных класса outhex и outoct, которые наследуют класс num. 
  Функция shownum( ) должна быть переопределена в производных классах так, чтобы осуществлять вывод на экран значений, в шестнадцатеричной и восьмеричной системах счисления соответственно.*/

#include <iostream>
#include "iomanip"


using namespace std;


class Num{
protected:
   int num;
public:
   Num(int n=0):num(n){}


   virtual void showNum(){
       cout<<"Decimal: "<<num<<endl;
   }
};


class Outhex:public Num{
public:
   Outhex(int n):Num(n){}
   void showNum(){
       cout<<"Hexadecimal: 0x"<<hex<<num<<endl;
   }
};


class Outoct:public Num{
public:
   Outoct(int n): Num(n){}
   void showNum(){
       cout<<"Octal: 0"<<oct<<num<<endl;
   }
};
int main() {
   Num* numDecimal = new Num(10);
   numDecimal->showNum();//Decimal


   Num*numHexadecimal = new Outhex(10);
   numHexadecimal->showNum();//Hexadecimal


   Num*numOctal= new Outoct(10);
   numOctal->showNum();//Octal
   return 0;
}

/*используя абстрактный базовый класс «фигура», разработанный самостоятельно, определить класс «квадрат»;
также предусмотреть динамическое создание объектов, в том числе создание массивов объектов, динамическое уничтожение объектов, 
изменение параметров объекта (цвет, размер, координаты и т.п.), отображение объектов на экране.*/

#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
class Figure {
protected:
   int x, y;  // координаты центра фигуры
   string color;  // цвет фигуры
public:
   Figure(int x, int y, string color) : x(x), y(y), color(color) {}
   virtual ~Figure() {}
   virtual void draw(sf::RenderWindow& window) = 0;
   virtual void setColor(string c) {
       color = c;
   }
   virtual void resize(int new_size) = 0;
   // и другие функции для изменения параметров фигуры
};


class Square : public Figure {
private:
   int size;  // размер стороны квадрата
   sf::RectangleShape square; // объект-отрисовщик квадрата
public:
   Square(int x, int y, string color, int size) : Figure(x, y, color), size(size) {
       square.setPosition(sf::Vector2f(x, y));
       square.setSize(sf::Vector2f(size, size));
       square.setFillColor(sf::Color::White);
       square.setOutlineThickness(2);
       square.setOutlineColor(sf::Color::Black);
   }
   void draw(sf::RenderWindow& window) {
       // установка цвета квадрата по имени
       if (color == "red") {
           square.setFillColor(sf::Color::Red);
       } else if (color == "green") {
           square.setFillColor(sf::Color::Green);
       } else if (color == "blue") {
           square.setFillColor(sf::Color::Blue);
       }
       // отрисовка квадрата
       window.draw(square);
   }
   void resize(int new_size) {
       size = new_size;
       square.setSize(sf::Vector2f(size, size));
   }
   // и другие функции для изменения параметров квадрата
};

int main() {
   sf::RenderWindow window(sf::VideoMode(400,400),"SFML");
   Square square(100, 0, "green", 50);


   // основной цикл приложения
   while (window.isOpen()) {
       // обработка событий
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed) {
               window.close();
           }
       }

       // обновление экрана
       window.clear();
       square.draw(window);
       window.display();
   }
   return 0;
}

