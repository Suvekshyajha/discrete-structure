#include <iostream>
using namespace std;
void extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
int main() {
    int coefficients[10], moduli[10], modInverses[10];
    int numCongruences, productOfModuli = 1, solution = 0;

    cout << "Enter the number of linear congruences: ";
    cin >> numCongruences;

    cout << "Enter the coefficients and moduli for each congruence:\n";
    for (int i = 0; i < numCongruences; i++) {
        cout << "Congruence " << i + 1 << ":\n";
        cout << "Coefficient (a): ";
        cin >> coefficients[i];
        cout << "Modulus (n): ";
        cin >> moduli[i];
    }

    // Calculate the product of all moduli
    for (int i = 0; i < numCongruences; i++) {
        productOfModuli *= moduli[i];
    }

    cout << "\nM (product of moduli) = " << productOfModuli << endl;

    int M_over_n[numCongruences];
    for (int i = 0; i < numCongruences; i++) {
        M_over_n[i] = productOfModuli / moduli[i];
        cout << "m" << i << " = M/n" << i << " = " << M_over_n[i] << endl;
    }

    // Calculate the modular inverses
    for (int i = 0; i < numCongruences; i++) {
        int x, y;
        extendedEuclidean(M_over_n[i], moduli[i], x, y);
        modInverses[i] = (x % moduli[i] + moduli[i]) % moduli[i];
        cout << "m" << i << "' (inverse of m" << i << " modulo n" << i << ") = " << modInverses[i] << endl;
    }

    // Calculate the solution using the Chinese Remainder Theorem
    for (int i = 0; i < numCongruences; i++) {
        solution = (solution + coefficients[i] * M_over_n[i] * modInverses[i]) % productOfModuli;
    }

    cout << "\nSolution: x = " << solution << " (mod " << productOfModuli << ")" << endl;

    return 0;
}


