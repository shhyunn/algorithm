#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> maps;
int move_x[4] = {0,1,0,-1}; // 왼, 아래, 오, 위
int move_y[4] = {-1,0,1,0};

int wind_x[4][9] = {{-1,-1,-1,1,1,1,-2,2,0}, {1,0,-1,1,0,-1,0,0,2}, {-1,-1,-1,1,1,1,-2,2,0}, {-1,0,1,-1,0,1,0,0,-2}};
int wind_y[4][9] = {{-1,0,1,-1,0,1,0,0,-2}, {-1,-1,-1,1,1,1,-2,2,0}, {1,0,-1,1,0,-1,0,0,2}, {-1,-1,-1,1,1,1,-2,2,0}};
float percents[9] = {0.1,0.07,0.01,0.1,0.07,0.01,0.02,0.02,0.05};

int answer = 0;

pair<int,int> move_storm(int x, int y, int step, int dir) {
    int cx, cy, kx, ky, rx, ry;
    int init_power;
    int power;

    while (step--) {
        cx = x + move_x[dir];
        cy = y + move_y[dir];

        power = maps[cx][cy];
        init_power = maps[cx][cy];
        maps[cx][cy] = 0;

        for (int i = 0; i < 9; i++) {
            kx = cx + wind_x[dir][i];
            ky = cy + wind_y[dir][i];

            int dust = init_power * percents[i];
            // cout << "dust" << dust << endl;
            if (0 <= kx && kx < N && 0 <= ky && ky < N) {
                maps[kx][ky] += dust;

            } else {
                answer += dust;
            }

            power -= dust;
        }

        rx = cx + move_x[dir];
        ry = cy + move_y[dir];

        if (0 <= rx && rx < N && 0 <= ry && ry < N) {
            maps[rx][ry] += power;

        } else {
            answer += power;
        }

        x = cx;
        y = cy;

        if (x == 0 && y == 0) break;
    }

    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    maps.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }

    int x = N / 2;
    int y = N / 2;

    int dir = 0;
    int step = 1;
    int cnt = 2;

    while (!(x == 0 && y == 0)) {

        cnt--;

        pair<int, int> k = move_storm(x, y, step, dir);
        x = k.first;
        y = k.second;

        // cout << x << " " << y << endl;

        dir = (dir + 5) % 4;

        if (cnt == 0) {
            step++;
            cnt = 2;
        }
    }


    cout << answer << endl;

    
    return 0;
}