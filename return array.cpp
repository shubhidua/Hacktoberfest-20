#include <iostream>
using namespace std;
int *retArray() {
   static int arr[10];
   for(int i = 0; i<10; i++) {
      arr[i] = i+1;
   }
   return arr;
}
int main() {
   int *ptr = retArray();
   cout <<"The array elements are: ";
   for(int i = 0; i<10; i++) {
      cout<< ptr[i] <<" ";
   }
   return 0;
}