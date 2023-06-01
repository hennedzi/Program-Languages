/*Цели задания — изучить алгоритмы работы с динамическими структурами данных в виде стека.

Постановка задачи:
написать программу по созданию, добавлению, просмотру и решению индивидуального задания для однонаправленного линейного списка типа СТЕК;
заданиях создать список из положительных и отрицательных случайных целых чисел;
реализовать сортировку стека двумя методами;*/

#include <iostream>

using namespace std;
struct Node {
   int data;
   Node* next;
};
class Stack {
private:
   Node* top;
public:
   Stack() {
       top = nullptr;
   }
   void push(int value) {
       Node* newNode = new Node;
       newNode->data = value;
       newNode->next = top;
       top = newNode;
   }
   void pop() {
       if (top == nullptr) {
           return;
       }
       Node* temp = top;
       top = top->next;
       delete temp;
   }
   void display() {
       Node* temp = top;
       while (temp != nullptr) {
           std::cout << temp->data << " ";
           temp = temp->next;
       }
       std::cout << std::endl;
   }
   void sort() {
       if (top == nullptr || top->next == nullptr) {
           return;
       }
       Node* current = top;
       Node* index = nullptr;
       int temp;
       while (current != nullptr) {
           index = current->next;
           while (index != nullptr) {
               if (current->data > index->data) {
                   temp = current->data;
                   current->data = index->data;
                   index->data = temp;
               }
               index = index->next;
           }
           current = current->next;
       }
   }
};
int main() {
   Stack stack;
   stack.push(5);
   stack.push(2);
   stack.push(8);
   stack.push(1);
   stack.push(-5);
   stack.push(-2);
   stack.push(-8);
   stack.push(-1);
   std::cout << "Before sorting: ";
   stack.display();
   stack.sort();
   std::cout << "After sorting: ";
   stack.display();
   return 0;
}

