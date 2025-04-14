#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> dp;
vector<int> lst;

int N;

int main() {
    cin >> N;
    dp.resize(N);
    lst.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> lst[i];
    }

    dp[0] = lst[0];
    int max_value;

    for (int i = 1; i < N; i++) {
        max_value = 0;

        for (int j = 0; j < N; j++) {
            if (lst[i] > lst[j] && dp[j] > max_value) {
                max_value = dp[j];
            }
        }
        dp[i] = max_value + lst[i];
    }

    int res = *max_element(dp.begin(), dp.end());

    cout << res;

    return 0;
}