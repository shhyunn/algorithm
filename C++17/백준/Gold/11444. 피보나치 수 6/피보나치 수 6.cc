#include <iostream>
using namespace std;

const long long MOD = 1000000007;

struct Matrix {
    long long a, b, c, d;
};

Matrix multiply(Matrix x, Matrix y) {
    return {
        (x.a*y.a + x.b*y.c) % MOD,
        (x.a*y.b + x.b*y.d) % MOD,
        (x.c*y.a + x.d*y.c) % MOD,
        (x.c*y.b + x.d*y.d) % MOD
    };
}

Matrix power(Matrix base, long long exp) {
    if (exp == 1) return base;

    Matrix half = power(base, exp / 2);
    Matrix result = multiply(half, half);

    if (exp % 2)
        result = multiply(result, base);

    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    Matrix base = {1, 1, 1, 0};
    Matrix result = power(base, n);

    cout << result.b << endl; // F(n)
}