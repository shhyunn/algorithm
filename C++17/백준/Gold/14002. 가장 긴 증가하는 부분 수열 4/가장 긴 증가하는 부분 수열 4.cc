#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> arr;
vector<vector<int> > dp;


int main() {
    cin >> N;
    arr.resize(N);
    dp.resize(N, vector<int>());

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i].push_back(i);

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j].size() + 1 > dp[i].size()) {
                dp[i] = dp[j];
                dp[i].push_back(i);
            }
        }      
    }
    int max_len = 0, max_index = 0;

    for (int i = 0; i < N; i++) {
        if (dp[i].size() > max_len) {
            max_index = i;
            max_len = dp[i].size();
        }
    }

    cout << max_len << "\n";

    for (int j = 0; j < dp[max_index].size(); j++) {
        cout << arr[dp[max_index][j]] << " ";
    }

    return 0;
}