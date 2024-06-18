#include <iostream>
using namespace std;


// Returns the greatest common divisor (gcd) of a and b,
// and the coefficients x and y such that ax + by = gcd(a, b)
int extendedEuclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to solve the linear congruence equation ax = b (mod m)
void solveLinearCongruence(int a, int b, int m) {
    int x, y, gcd;
    gcd = extendedEuclidean(a, m, x, y);

    // Check if a solution exists
    if (b % gcd != 0) {
        cout << "No solution exists." << endl;
        return;
    }

    // Adjusting x to be non-negative
    x = (x * (b / gcd)) % m;
    if (x < 0)
        x = (x + m) % m;

    
    cout << "x = " << x << " (mod " << m << ")" << endl;
}

int main() {
    int a, b, m;
    cout << "Enter the values of a, b, and m for the equation ax = b (mod m): ";
    cin >> a >> b >> m;
    solveLinearCongruence(a, b, m);
    return 0;
}
