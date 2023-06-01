/*Создайте функцию min (  ), которая возвращает наименьший из двух численных аргументов, 
используемых при вызове функции. Перегрузите min (  ) так, чтобы она воспринимала в качестве аргументов символы, целые и действительные двойной точности.*/

double min(double a,double b){
   double result = a<b?a:b;
   return result;
}
int min(int a,int b){
   int result = a<b?a:b;
   return result;
}
char min(char a,char b){
   char result = a<b?a:b;
   return result;
}

/*Создать класс “вектор целых чисел”, определить для него операции:
сложение векторов с сохранением значения в одном из них (операция  +=  );
сложение векторов с сохранением значения в новом векторе (операция  +  );
вычитание векторов с сохранением значения в одном из них (операция  -=  );*/

class Vector3 {
public:
   int x;
   int y;
   int z;


   Vector3(int X=0,int Y=0,int Z=0){
       x=X;
       y=Y;
       z=Z;
   }
   Vector3 operator +(const Vector3& vector3)
   {
       return Vector3(x+vector3.x,y+vector3.y,z+vector3.z);
   }
   Vector3& operator -=(const Vector3& vector3){
       x-=vector3.x;
       y-=vector3.y;
       z-=vector3.z;
       return *this;
   }
   Vector3& operator +=(const Vector3& vector3){
       x+=vector3.x;
       y+=vector3.y;
       z+=vector3.z;
       return *this;
   }
};

/*определите класс «string» с двумя член-данными: char *p – указатель на строку, int len – длина строки;
определить один конструктор и деструктор (предусмотреть выдачу сообщения об их работе);
переопределить операцию "+" для сложения объектов класса;
определить член функцию, выводящую строку на экран;
написать демонстрационную версию программы, которая создает 2 объекта класса «string», выводит строки этих объектов на экран, складывает эти объекты и выводит на экран результирующую строку обоих;*/

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
   char* p;
   int len;
public:
   String(const char* str) {
       len = strlen(str);
       p = new char[len + 1];
       strcpy(p, str);
       cout << "Constructor is called" << endl;
   }
   ~String() {
       delete[] p;
       cout << "Destructor is called" << endl;
   }

   String operator+(const String& other) const {
       int newLen = len + other.len;
       char* newP = new char[newLen + 1];
       strcpy(newP, p);
       strcat(newP, other.p);
       return String(newP);
   }

   void print() const {
       cout << p << endl;
   }
   int getLenght(){
       return len;
   }
};


int main() {
   String surname("Ivanov");
   cout << surname.getLenght()<<endl;
   String name("Ivan");


   cout << name.getLenght()<<endl;
   cout << "Surname: ";
   surname.print();


   cout << "Name: ";
   name.print();


   String fullName = surname + name;
   cout << "Full name: ";
   fullName.print();
   cout << fullName.getLenght()<<endl;


   return 0;
}




