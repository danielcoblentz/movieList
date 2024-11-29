#include <iostream>
using namespace std;
//fib function to calc the sum of the sequence
int sumFibonacci(int n) {
    if (n == 1) return 1;  // Base case

    int a = 1, b = 1, sum = a + b;
    if (n == 2) return sum;

    for (int i = 3; i <= n; ++i) {
        int next = a + b;
        sum += next;
        a = b;
        b = next;
    }

    return sum;
}



int main() {
    int n;

    // input the number of terms
    cout << " plz enter the number of fibonacci terms to sum: ";
    cin >> n;

    // n >= 1 incase users try to enter 0 for teh input n value
    if (n < 1) {
        cout << "number of terms must be at least 1" << endl;
        return 1;
    }

    //output for the sum of the first n fibonacci numbers
    cout << "sum of the first " << n << " fibonacci numbers is: " << sumFibonacci(n) << endl;

    return 0;
}


