#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int C, N;
vector<int> dp;
vector<pair<int , int>> cost_map;

bool compare_func(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> C >> N;

    dp.assign(C + 101, 1e9);
    dp[0] = 0;

    int cost, people;
    for (int i = 0; i < N; i++) {
        cin >> cost >> people;
        cost_map.push_back({cost, people});
    }
    sort(cost_map.begin(), cost_map.end(), compare_func); //사람수 대로 오름차순 정렬

    for (pair<int, int>& a : cost_map) { //가격, 사람 수
        for (int c = a.second; c < C + 101; c++) { //인덱스 - 사람 수
            dp[c] = min(dp[c-a.second] + a.first, dp[c]); //최솟값 비교를 위해 dp[0]은 0으로 초기화 필요
        }
    }
    int answer = 1e9;
    for (int c = C; c < C+101; c++) {
        answer = min(answer, dp[c]);
    }

    cout << answer << endl;
    return 0;
}