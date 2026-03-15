#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> maps;
vector<vector<int>> visited;
int x, y;
int move_x[4] = {-1,0,0,1};
int move_y[4] = {0,-1,1,0};

struct Point {
    int x, y, dist;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    maps.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];

            if (maps[i][j] == 9) {
                x = i;
                y = j;
                maps[i][j] = 0;
            }
        }
    }
    bool is_continue = true;

    int curr_size = 2; //초기 물고기 크기
    int curr_cnt = 0; //먹은 물고기 개수
    int total_time = 0;

    while (is_continue) {
        //가장 가까운 물고기 찾기
        queue<Point> q;
        q.push({x, y, 0});
        visited.assign(N, vector<int>(N, false));
        visited[x][y] = true;
        is_continue = false;

        vector<Point> eating_fish;

        int fx = -1, fy = -1;
        int min_dist = 1e9;

        while (!q.empty()) {
            Point k = q.front(); q.pop();

            if (maps[k.x][k.y] < curr_size && maps[k.x][k.y] > 0) { //먹을 수 있다면
                if (k.dist < min_dist || (k.dist == min_dist && (k.x < fx || k.x == fx && k.y < fy))) {
                    fx = k.x;
                    fy = k.y;
                    min_dist = k.dist;
                }
            }

            for (int i = 0; i < 4; i++) {
                int cx = k.x + move_x[i];
                int cy = k.y + move_y[i];

                if (0 <= cx && cx < N && 0 <= cy && cy < N && maps[cx][cy] <= curr_size && !visited[cx][cy]) { //이동 가능하다면
                    q.push({cx, cy, k.dist+1});
                    visited[cx][cy] = true;
                }
            }
        }

        if (fx != -1) {
            curr_cnt++;
            total_time += min_dist;
            maps[fx][fy] = 0;
            x = fx;
            y = fy;
            is_continue = true;         
        }

        if (is_continue && curr_size == curr_cnt) {
            curr_size++;
            curr_cnt = 0;
        }
    }
    
    cout << total_time << endl;

    return 0;
}