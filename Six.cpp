/*Найти наибольший общий делитель чисел M и N, используя теорему Эйлера: если M делится на N, то НОД (N,M) = N, иначе НОД (N,M) = (M%N, N).*/

#include <iostream>

int Rgcd(int m, int n) {
   if (m % n == 0) {
       return n;
   } else {
       return Rgcd(n, m % n);
   }
}
int gcd(int m, int n) {
   while (m % n != 0) {
       int temp = m % n;
       m = n;
       n = temp;
   }
   return n;
}
int main() {
   int m, n;
   std::cout << "Enter two numbers: ";
   std::cin >> m >> n;
   std::cout << "Recursion GCD(" << m << ", " << n << ") = " << Rgcd(m, n) << std::endl;




   std::cout << "Enter two numbers: ";
   std::cin >> m >> n;
   std::cout << "Default GCD(" << m << ", " << n << ") = " << gcd(m, n) << std::endl;
   return 0;
}

