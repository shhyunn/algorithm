#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int T, N, K, W;
int arr[MAX];
vector<pair<int, int> > sequence;
int dp[MAX];

int dfs(int v) {
    if (dp[v] != -1) return dp[v];
    //sequence 중 second가 있다면 계속 출력
    int sum = 0;
    for (int i = 1; i < K+1; i++) {
        if (sequence[i].second == v) { // 선행 주자가 있을 경우
            sum = max(sum, dfs(sequence[i].first));
        }
    }

    dp[v] = sum + arr[v];

    return dp[v];
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        sequence.resize(K+1);

        for (int i = 1; i < N+1; i++) {
            cin >> arr[i]; //건물 짓는데 걸리는 시간
            dp[i] = -1;
        };

        for (int i = 1; i < K+1; i++) {
            cin >> sequence[i].first >> sequence[i].second;
        }
        cin >> W;

        int res = dfs(W);
        cout << res << '\n';

    }

    return 0;
}