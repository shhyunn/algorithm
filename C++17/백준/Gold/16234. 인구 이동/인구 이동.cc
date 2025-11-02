#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int N, L, R;
int cnt = 0;
vector<vector<int>> maps;
vector<vector<int>> visited;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0,0, -1, 1};


int move_people(int x, int y) {
    deque<pair<int, int>> stack;
    stack.push_back({x, y});
    visited[x][y] = 1;

    vector<pair<int, int>> temp;
    int sum_cnt = maps[x][y];
    temp.push_back({x, y});

    while (!stack.empty()) {
        auto [i, j] = stack.front(); stack.pop_front();

        for (int m = 0; m < 4; m++) {
            int ci = i + move_x[m];
            int cj = j + move_y[m];

            if (ci >= 0 && ci < N && cj >= 0 && cj < N && abs(maps[ci][cj] - maps[i][j]) >= L && abs(maps[ci][cj] - maps[i][j]) <= R && !visited[ci][cj]) {
                stack.push_back({ci, cj});
                visited[ci][cj] = 1;

                sum_cnt += maps[ci][cj];
                temp.push_back({ci, cj});
            }
        }
    }

    if (temp.size() == 1) return 0;
    int resized_num = sum_cnt / temp.size();
    for (auto [ix, iy] : temp) {
        maps[ix][iy] = resized_num;
    }
    return 1;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    maps.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<int>(N, 0));

    for (int n = 0; n < N; n++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[n][j];
        }
    }

    while (true) {
        for (auto& v : visited) {
            fill(v.begin(), v.end(), 0); //방문 초기화
        }
        int moved = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                if (move_people(i, j)) moved = 1;
            }
        }

        if (!moved) break;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}