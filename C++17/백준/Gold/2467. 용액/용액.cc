#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long N;
    cin >> N;
    vector<long long> arr;
    long long tmp;

    for (int i = 0; i < N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
    }

    long long left = 0;
    long long right = N - 1;
    long long sum_value = LLONG_MAX;
    long long t;
    long long res1; long long res2;

    while (left < right) {
        t = arr[left] + arr[right];
        if (abs(t) < sum_value) {
            sum_value = abs(t);
            res1 = arr[left];
            res2 = arr[right];

            if (sum_value == 0) {
                break;
            }
        }

        if (t > 0) {
            right--;
        } else {
            left++;
        }
    }

    cout << res1 << " " << res2 << endl; 

    return 0;
}