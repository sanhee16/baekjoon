#include <iostream>
using namespace std;


int main() {
   int N;
   bool done = false;
   int x, y = 0;
   cin >> N;
   for (int i = 0; i<int(N / 3) + 1; i++) {
      for (int j = 0; j<int(N / 5) + 1; j++) {
         if (N == 3 * i + 5 * j) {
            x = i;
            y = j;
            done = true;
            break;
         }
      }
      if (done == true) {
         break;
      }
   }
   if (done == false) {
      cout << "-1";
   }
   else {
      cout << x + y;
   }
   return 0;
}
