#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > arr;
vector<int> dp;

int main() {
    cin >> N;
    arr.resize(N);
    dp.resize(N, 1); //1로 초기화

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].second) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int lis = *max_element(dp.begin(), dp.end());

    cout << N - lis;

    return 0;
}