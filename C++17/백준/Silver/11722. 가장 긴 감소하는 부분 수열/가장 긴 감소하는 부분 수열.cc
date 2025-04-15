#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> arr;
vector<int> dp;

int main() {
    cin >> N;
    arr.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //가장 긴 감소하는 수열 길이
    dp[0] = 1;
    int max_value;
    for (int i = 1; i < N; i++) {
        max_value = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[j] > max_value) {
                max_value = dp[j];
            }
        }
        dp[i] = max_value + 1;
    }

    int res = *max_element(dp.begin(), dp.end());

    cout << res;
    return 0;
}