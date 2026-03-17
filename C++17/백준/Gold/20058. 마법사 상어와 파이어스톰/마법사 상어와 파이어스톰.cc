#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, Q;

vector<vector<int>> maps;
vector<vector<int>> visited;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

void rotate_ice(int l) {
    int step = 1 << l;

    vector<vector<int>> temp = maps;

    for (int i = 0; i < N; i += step) {
        for (int j = 0; j < N; j += step) {

            for (int x = 0; x < step; x++) { //회전
                for (int y = 0; y < step; y++) {

                    maps[i + y][j + step - 1 - x] = temp[i + x][j + y]; //90도 시계방향 회전

                }
            }
        }
    }
}

void reduce_ice() {
    int cnt, cx, cy;
    vector<vector<int>> temps = maps;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt = 0;

            if (maps[i][j] == 0) continue;

            for (int d = 0; d < 4; d++) {
                cx = i + move_x[d];
                cy = j + move_y[d];

                if (0 <= cx && cx < N && 0 <= cy && cy < N && maps[cx][cy]) cnt++;
            }

            if (cnt < 3) temps[i][j]--;
        }
    }
    maps = temps;
}

pair<int, int> process_ice(int x, int y) {
    deque<pair<int,int>> q;
    q.push_back({x,y});
    
    int cnt = 0;
    int volume = 0;
    visited[x][y] = 1;

    while (!q.empty()) {
        auto k = q.front(); q.pop_front();
        cnt++;
        volume += maps[k.first][k.second];

        for (int i = 0; i < 4; i++) {
            int cx = k.first + move_x[i];
            int cy = k.second + move_y[i];

            if (0 <= cx && cx < N && 0 <= cy && cy < N && maps[cx][cy] > 0 && !visited[cx][cy]) {
                visited[cx][cy] = 1;
                q.push_back({cx, cy});
            }
        }
    }

    return {cnt, volume};
}

pair<int, int> calculate_ice() {
    int max_size = 0;
    int total_size = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (visited[i][j] || !maps[i][j]) continue;

            pair<int, int> g = process_ice(i,j);
            max_size = max(max_size, g.first);
            total_size += g.second;
        }
    }

    return {total_size, max_size};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> Q;
    N = 1 << M;
    maps.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }

    int l;

    for (int i = 0; i < Q; i++) {
        cin >> l;
        rotate_ice(l);
        reduce_ice();
    }

    pair<int, int> answer = calculate_ice();
    cout << answer.first << "\n" << answer.second << endl;

    return 0;
}