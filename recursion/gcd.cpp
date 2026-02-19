//The Greatest Common Divisor (GCD) of two numbers is the largest number that divides both of them. 
//Method 1:============================================================================================================================================================================================================================================
#include<iostream>
using namespace std;
int gcd(int a, int b) {
   if (a == 0 || b == 0)
   return 0;
   else if (a == b)
   return a;
   else if (a > b)
   return gcd(a-b, b);
   else return gcd(a, b-a);
}
int main() {
   int a = 63, b = 42;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}
//Method 2: -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main() {
   int a = 63, b = 42;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}
