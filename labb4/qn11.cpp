#include <iostream>

int power(int a, int n) {
    // Base case: any number raised to the power of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case
    return a * power(a, n - 1);
}

int main() {
    int a, n;
    std::cout << "Enter base (a): ";
    std::cin >> a;
    std::cout << "Enter exponent (n): ";
    std::cin >> n;

    int result = power(a, n);
    std::cout << a << "^" << n << " = " << power(a,n)<< std::endl;

    return 0;
}

