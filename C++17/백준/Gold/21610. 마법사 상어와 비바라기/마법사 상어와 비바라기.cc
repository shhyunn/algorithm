#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> maps;

int move_x[9] = {0,0,-1,-1,-1,0,1,1,1};
int move_y[9] = {0,-1,-1,0,1,1,1,0,-1};

vector<pair<int,int>> clouds;

void move_cloud(int d, int s) {
    for (int i = 0; i < clouds.size(); i++) {
        auto c = clouds[i];
        int cx = (c.first + move_x[d] * s % N + N) % N;
        int cy = (c.second + move_y[d] * s % N + N) % N;

        clouds[i] = {cx, cy};
    }
}

void add_water() {
    for (auto c : clouds) {
        maps[c.first][c.second]++;
    }
}

void copy_water() {
    for (auto c : clouds) {
        int cnt = 0;

        for (int i = 2; i < 9; i += 2) {
            int cx = c.first + move_x[i];
            int cy = c.second + move_y[i];

            if (0 <= cx && cx < N && 0 <= cy && cy < N && maps[cx][cy] > 0) {
                cnt++;
            }
        }

        maps[c.first][c.second] += cnt;
    } 
}

void create_clouds() {
    vector<vector<bool>> is_cloud(N, vector<bool>(N, false));
    vector<pair<int, int>> temp_clouds;

    for (auto c : clouds) {
        is_cloud[c.first][c.second] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maps[i][j] >= 2 && !is_cloud[i][j]) {
                temp_clouds.push_back({i, j});
                maps[i][j] -= 2;
            }
        }
    }

    clouds = temp_clouds;
}

void calculate_water() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer += maps[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    maps.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }

    clouds = {{N-1,0}, {N-1, 1}, {N-2, 0}, {N-2,1}}; //클라우드 초기화

    int d, s;

    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        move_cloud(d, s); //구름 이동
        add_water();
        copy_water();
        create_clouds();
    }
    calculate_water();

    cout << answer << endl;
    
    return 0;
}