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
/*Создайте класс, реализующий стек символов. Сделайте стек длиной 10 символов. Члены класса: стек (массив символов), 
индекс вершины стека. Обязательны функции-члены класса для инициализации стека (присваивает индексу нулевое значение), 
помещения значения в стек, выталкивания значения из стека. Продемонстрировать использование класса.*/

#include <iostream>


using namespace std;


class CharStack {
private:
   char stack[10];
   int topIndex;
public:
   CharStack() : topIndex(-1)
   {
   }
   void push(char c)
   {
       // Проверяем, не переполнен ли стек
       if (topIndex >= 9) {
           cerr << "Stack overflow" << endl;
           return;
       }
       // Увеличиваем индекс вершины стека и записываем значение
       stack[++topIndex] = c;
   }
   char pop()
   {
       // Проверяем, не пуст ли стек
       if (topIndex < 0) {
           cerr << "Stack is empty" << endl;
           return '\0';
       }
       // Возвращаем значение и уменьшаем индекс вершины стека
       return stack[topIndex--];
   }
};


int main()
{
   CharStack stack;


   // добавляем символы в стек
   stack.push('a');
   stack.push('b');
   stack.push('c');


   // извлекаем символы из стека
   cout << "pop: " << stack.pop() << endl;
   cout << "pop: " << stack.pop() << endl;


   // добавляем еще символы в стек
   stack.push('d');
   stack.push('e');


   // извлекаем все символы из стека, пока он не станет пустым
   while (true) {
       char c = stack.pop();
       if (c == '\0') {
           break;
       }
       cout << "pop: " << c << endl;
   }


   return 0;
}

/*Класс `ComplexNumber` содержит переменные-члены `realPart` (вещественная часть)
   и `imaginaryPart` (мнимая часть) и методы-члены для ввода и вывода числа (`print`), сложения (`operator+`), умножения (`operator*`) и возведения числа в целую степень (`operator^`).
В конструкторе мы устанавливаем начальные значения вещественной и мнимой частей.
Метод `print` выводит комплексное число в формате a + bi (если мнимая часть является положительным числом) или a - bi (если мнимая часть является отрицательным числом).
Оператор `operator+` выполняет сложение двух комплексных чисел, складывая их вещественные и мнимые части.
Оператор `operator*` выполняет умножение двух комплексных чисел, используя формулу расширенного произведения:
`(a + bi) * (c + di) = ac - bd + (ad + bc)i`
Оператор `operator^` выполняет возведение комплексного числа в целую степень. Мы используем цикл для выполнения умножения комплексного числа на само себя `n` раз.*/
#include <iostream>
#include <cmath>


using namespace std;


class ComplexNumber {
private:
   double realPart;
   double imaginaryPart;


public:
   ComplexNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}


   void print() const {
       if (imaginaryPart >= 0) {
           cout << realPart << " + " << imaginaryPart << "i" << endl;
       } else {
           cout << realPart << " - " << abs(imaginaryPart) << "i" << endl;
       }
   }


   ComplexNumber operator+(const ComplexNumber& other) const {
       return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
   }


   ComplexNumber operator*(const ComplexNumber& other) const {
       return ComplexNumber(realPart * other.realPart - imaginaryPart * other.imaginaryPart,
                            realPart * other.imaginaryPart + imaginaryPart * other.realPart);
   }


   ComplexNumber operator^(const int& pow) const {
       ComplexNumber result = *this;
       for(int i = 1; i < pow; i++) {
           result = result * (*this);
       }
       return result;
   }
};


int main() {
   ComplexNumber c1(5,3);
   ComplexNumber c2(-2,4);


   cout << "Complex number 1: ";
   c1.print();


   cout << "Complex number 2: ";
   c2.print();


   cout << "Sum of two complex numbers: ";
   (c1 + c2).print();


   cout << "Product of two complex numbers: ";
   (c1 * c2).print();


   cout << "Complex number 1 to the power of 3: ";
   (c1 ^ 3).print();


   return 0;
}



