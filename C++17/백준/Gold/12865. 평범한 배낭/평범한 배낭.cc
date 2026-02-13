#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> dp;
vector<pair<int, int>> maps;

bool compare_func(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    dp.assign(K+1, 0);
    
    int w, v;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        maps.push_back({w, v});
    }

    sort(maps.begin(), maps.end(), compare_func);

    for (auto [w, v] : maps) { //물건의 무게와 가치
        for (int curr_w = K; curr_w >= w; curr_w--) { //물건을 넣을 때 물건을 넣을지 말지 결정
            dp[curr_w] = max(dp[curr_w], dp[curr_w - w] + v);
        }
    }

    int answer = 0;
    for (int i = 0; i < K+1; i++) {
        answer = max(dp[i], answer);
    }

    cout << answer << endl;

    return 0;
}