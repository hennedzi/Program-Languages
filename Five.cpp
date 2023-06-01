/*Создать шаблон класса «стек». Использовать его при решении следующей задачи:
Гаражная стоянка имеет одну стояночную полосу, причем въезд и выезд находятся в одном конце полосы. 
  Если владелец автомашины приходит забрать свой автомобиль, который не является ближайшим к выходу, 
то все автомашины, загораживающие проезд, удаляются, машина данного владельца выводится со стоянки, 
а другие машины возвращаются на стоянку в исходном порядке. Написать программу, которая моделирует процесс прибытия и отъезда машин. 
  Прибытие или отъезд автомашины задается командной строкой, которая содержит признак прибытия или отъезда и номер машины.
  Программа должна выводить сообщение при прибытии или выезде любой машины. 
  При выезде автомашины со стоянки сообщение должно содержать число раз, которое машина удалялась со стоянки для обеспечения выезда других автомобилей.*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
   vector<T> stack_;
public:
   void push(T element) {
       stack_.push_back(element);
   }
   void pop() {
       stack_.pop_back();
   }

   T top() const{
       if(empty()) throw std::logic_error("stack is empty");
       return stack_.back();
   }

   bool empty() const {
       return stack_.empty();
   }

   size_t size() const {
       return stack_.size();
   }
};

class Car {
public:
   explicit Car(int number) : number_(number), count_(0) {}
   int GetNumber() const {
       return number_;
   }
   int GetCount() const {
       return count_;
   }
   void IncCount() {
       count_++;
   }
private:
   int number_;
   int count_;
};

class Garage {
public:
   void AddCar(const Car& car) {
       cars_.push(car);
       cout << "Car " << car.GetNumber() << " added to garage" << endl;
   }
   void RemoveCar(int car_number) {
       Stack<Car> temp_cars;
       bool found = false;
       Car removed_car(0);
       while (!cars_.empty()) {
           Car current_car = cars_.top();
           if (current_car.GetNumber() == car_number) {
               found = true;
               removed_car = current_car;
               break;
           }
           temp_cars.push(current_car);
           cout << "Car " << cars_.top().GetNumber() << " free, "
                << cars_.top().GetCount() << " times freed the way for other cars" << endl;
           cars_.pop();
       }
       if (found) {
           cout << "Car " << removed_car.GetNumber() << " departure, "
                     << removed_car.GetCount() << " times freed the way for other cars" << endl;
           while (!temp_cars.empty()) {
               auto current_car = temp_cars.top();
               current_car.IncCount();
               temp_cars.pop();
               cars_.push(current_car);
           }
       } else {
           cerr << "Car " << car_number << " not found" << endl;
       }
   }
private:
   Stack<Car> cars_;
};

int main() {
   Garage garage;
   string input;
   int car_number;


   // Цикл для добавления машин
   cout << "Enter car numbers to add to garage (type exit to stop): ";
   while (true) {
       cin >> input;
       if (input == "exit") {
           break;
       } else {
           car_number = stoi(input);
           garage.AddCar(Car(car_number));
       }
   }

   // Цикл для удаления машин
   cout << "Enter car numbers to remove from garage (type exit to stop): ";
   while (true) {
       cin >> input;
       if (input == "exit") {
           break;
       } else {
           car_number = stoi(input);
           garage.RemoveCar(car_number);
       }
   }


   return 0;
}

