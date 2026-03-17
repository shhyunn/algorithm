#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K;

int move_x[8] = {-1,-1,0,1,1,1,0,-1};
int move_y[8] = {0,1,1,1,0,-1,-1,-1};

struct Fireball {
    int x, y, m, s, d;
};

vector<vector<vector<Fireball>>> maps;
vector<Fireball> fireball_arr;

void move_fireball() {
    for (Fireball f : fireball_arr) {
        int cx = (f.x + (move_x[f.d] * f.s) % N + N) % N;
        int cy = (f.y + (move_y[f.d] * f.s) % N + N) % N;

        maps[cx][cy].push_back({cx, cy, f.m, f.s, f.d});
    }
}

void collect_fireball() {
    vector<Fireball> new_fireball_arr;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maps[i][j].size() == 0) continue;

            else if (maps[i][j].size() == 1) {
                new_fireball_arr.push_back(maps[i][j][0]);

            } else { //2개 이상일 경우
                int total_m = 0;
                int total_s = 0;
                int total_d = -1;
                int total_size = maps[i][j].size();

                for (Fireball& f : maps[i][j]) {
                    total_m += f.m;
                    total_s += f.s;
                    if (total_d == -1) total_d = f.d % 2;
                    else if (total_d == f.d % 2) continue;
                    else total_d = 2;
                }

                int new_m = total_m / 5;
                int new_s = total_s / total_size;
                int new_d = total_d == 2 ? 1 : 0;

                for (int k = 0; k < 4; k++) {
                    if (new_m == 0) continue;
                    new_fireball_arr.push_back({i, j, new_m, new_s, new_d + 2 * k});
                }
            }
        }
    }

    fireball_arr = new_fireball_arr;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maps[i][j].clear();
        }
    }
}

int calculate_fireball() {
    int total_m = 0;

    for (Fireball& f : fireball_arr) {
        total_m += f.m;
    }

    return total_m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    maps.assign(N, vector<vector<Fireball>>(N));

    int r, c, m, s, d;

    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        r--; c--;
        fireball_arr.push_back({r,c,m,s,d});
    }

    while (K--) {
        move_fireball();
        collect_fireball();
    }

    int answer = calculate_fireball();

    cout << answer << endl;

    return 0;
}