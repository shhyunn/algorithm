#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VALUE 500
using namespace std;
int N, M;
int arr[MAX_VALUE][MAX_VALUE];
int dp[MAX_VALUE][MAX_VALUE];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int dfs(int x, int y) {
    if (x == 0 && y == 0) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    int cx, cy;
    dp[x][y] = 0;

    for (int d = 0; d < 4; d++) {
        cx = x + dx[d];
        cy = y + dy[d];

        if (0<=cx && cx < M && 0 <= cy && cy < N && arr[x][y] < arr[cx][cy]) {
            dp[x][y] += dfs(cx, cy);
        }
    }
    return dp[x][y];
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
        
    }

    int res = dfs(M-1,N-1);

    cout << res;

    return 0;
}