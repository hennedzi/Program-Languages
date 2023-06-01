/*Постановка задачи:
Определить классы и их иерархию, а также продемонстрировать использование введенных конструкций при работе. Человек : студент, преподаватель.*/

#include <iostream>

using namespace std;

class Person{
private:
   string _name;
   unsigned _age;
public:
   void print() const
   {
       cout<<"Name: "<<_name<<" Age: "<<_age<<endl;
   }
   Person(string n,unsigned a)
   {
       _name=n;
       _age=a;
   }
   Person(const Person& person){
       _name = person._name;
       _age = person._age;
   }

   virtual void DoJob(){}
};


class Teacher:public Person{
private:
   string _since;
public:
   Teacher(string n,int a,string s): Person(n,a){
       _since =s;
   }
   Teacher(const Teacher& teacher): Person(teacher){
       _since = teacher._since;
   }
   void DoJob() override{
       cout<<"Teach "<<_since<<endl;
   }
};


class Student:public Person{
private:
   string _since;
public:
   Student(string n,int a,string s): Person(n,a){
       _since =s;
   }
   Student(const Student& student): Person(student){
       _since = student._since;
   }
   void DoJob() override{
       cout<<"Learn "<<_since<<endl;
   }
};

int main() {
   Teacher hena = Teacher("Hena",22,"CS");
   Student max = Student("Max",14,"CS");
   hena.print();
   hena.DoJob();
   max.print();
   max.DoJob();
   return 0;
}

