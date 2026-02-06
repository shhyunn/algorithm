#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int N;
vector<vector<int>> maps;
vector<vector<int>> res_maps;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};
int seq = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }

        maps.assign(N, vector<int>(N, 0));
        res_maps.assign(N, vector<int>(N, INT_MAX));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> maps[i][j];
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.push({maps[0][0], 0, 0});
        res_maps[0][0] = maps[0][0];

        while (!pq.empty()) {
            auto [val, i, j] = pq.top(); pq.pop();
            if (val > res_maps[i][j]) continue;

            if (i == N-1 && j == N-1) break;

            for (int d = 0; d < 4; d++) {
                int ci = i + move_x[d];
                int cj = j + move_y[d];

                if (0 <= ci && ci < N && 0 <= cj && cj < N && res_maps[ci][cj] > val + maps[ci][cj]) {
                    pq.push({val + maps[ci][cj], ci, cj});
                    res_maps[ci][cj] = val + maps[ci][cj];
                }
            }
        }

        cout << "Problem " << seq + 1 << ": " << res_maps[N-1][N-1] << "\n";

        seq++;
    }

    return 0;
}