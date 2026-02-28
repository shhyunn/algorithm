#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(3));
    for (int i = 0; i < N; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int answer = INF;

    // 시작 색 고정 (0:R, 1:G, 2:B)
    for (int start = 0; start < 3; start++) {

        vector<vector<int>> dp(N, vector<int>(3, INF));

        // 첫 집 강제 선택
        dp[0][start] = cost[0][start]; //시작 위치를 기준으로 3번 돌리자. 시작 집 제외하고는 모두 INF 값으로 남겨두기

        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        // 마지막 집: 시작 색 제외
        for (int end = 0; end < 3; end++) {
            if (start == end) continue; //시작 집과 끝집의 색깔이 같은 경우는 제외
            answer = min(answer, dp[N-1][end]);
        }
    }

    cout << answer << '\n';
}