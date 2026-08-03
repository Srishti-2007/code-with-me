#include <iostream>
using namespace std;
int check(int n)
{
    if (n == 1) return 1;              // base case: 1 is a power of 2
    if (n % 2 != 0 || n <= 0) return 0; // odd or zero → not a power of 2
    return check(n / 2);               // keep dividing by 2
   
}
int main()
{
    int n = 10;
    cout << check(n);
}