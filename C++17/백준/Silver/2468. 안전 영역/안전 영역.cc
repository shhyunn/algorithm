#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> maps;
vector<vector<int>> visited;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

void bfs(int x, int y, int st) {
    deque<pair<int, int>> stack;
    stack.push_back({x, y});
    visited[x][y] = 1;

    while (!stack.empty()) {
        auto [cx, cy] = stack.front(); stack.pop_front();

        for (int i = 0; i < 4; i++) {
            int tx = cx + move_x[i];
            int ty = cy + move_y[i];

            if (0 <= tx && tx < N && 0 <= ty && ty < N && !visited[tx][ty] && maps[tx][ty] > st) {
                stack.push_back({tx, ty});
                visited[tx][ty] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    
    maps.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<int>(N, 0));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }

    int max_cnt = 1;

    for (int s = 1; s < 101; s++) {
        int cnt = 0;

        for (auto& row : visited) {
            fill(row.begin(), row.end(), 0);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || maps[i][j] <= s) continue; //이미 방문했거나 침수된 지역일 경우
                bfs(i,j, s);
                cnt++;
            }
        }

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << endl;
    return 0;
}