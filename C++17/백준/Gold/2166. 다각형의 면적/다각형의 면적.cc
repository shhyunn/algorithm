#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<double> X; vector<double> Y;
    int N; double x; double y;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }

    double value = 0.0;

    for (int i = 2; i < N; i++) {
        value += (X[0] * Y[i-1] + X[i-1] *Y[i] + X[i] * Y[0]);
        value -= (X[i-1] * Y[0] + X[i] * Y[i-1] + X[0] * Y[i]);
    }

    value = 0.5 * abs(value);
    cout << fixed << setprecision(1) << value <<endl;
    
    return 0;
}