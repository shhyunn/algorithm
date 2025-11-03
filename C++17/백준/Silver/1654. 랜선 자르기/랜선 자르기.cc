#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int K, N;
vector<long long> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    arr.resize(K);
    long long start = 1; long long end = 0;

    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    end = *max_element(arr.begin(), arr.end());
    
    long long max_cnt = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;

        long long temp = 0;

        for (int i = 0; i < K; i++) {
            temp += (arr[i] / mid);
        }

        if (temp >= N) {
            max_cnt = max(max_cnt, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << max_cnt << endl;

    return 0;
}