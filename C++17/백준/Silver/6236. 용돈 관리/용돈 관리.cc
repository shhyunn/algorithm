#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long COST_MAX = 1000000000;
int N, M;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.assign(N, 0);
    int max_cost = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max_cost = max(arr[i], max_cost);
    }

    long long left = static_cast<long long>(max_cost);
    long long right = COST_MAX;

    while (left < right) {
        long long mid = (left + right) / 2;

        int cnt = 0;
        long long rest_cost = 0;

        for (int i = 0; i < N; i++) {
            if (rest_cost < arr[i]) {
                rest_cost = (mid - arr[i]);
                cnt++;

            } else {
                rest_cost -= arr[i];
            }
        }

        if (cnt <= M) {
            right = mid;

        } else {
            left = mid + 1;
        }

    }

    cout << left << endl;

   
    return 0;
}