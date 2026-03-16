#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;
vector<vector<int>> maps;
vector<pair<int, int>> viruses;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

struct Virus {
    int x, y, time;
};

bool check_virus() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maps[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    maps.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
            //2 비활성 바이러스,  1 벽, 0 빈 칸
            if (maps[i][j] == 2) {
                viruses.push_back({i, j});
                K++;
            }
        }
    }

    vector<int> combi(K);
    fill(combi.begin()+K-M, combi.end(), 1); //K개 중 M개 선택
    vector<vector<int>> init_maps = maps;

    int total_time = 1e9;

    do {
        deque<Virus> q;
        maps = init_maps;

        for (int k = 0; k < K; k++) {
            if (combi[k]) {
                q.push_back({viruses[k].first, viruses[k].second, 0});
                maps[viruses[k].first][viruses[k].second] = 3; //활성화 바이러스
            }
        }
        
        int max_time = 0;

        while (!q.empty()) {
            Virus v = q.front(); q.pop_front();

            for (int i = 0; i < 4; i++) {
                int cx = v.x + move_x[i];
                int cy = v.y + move_y[i];

                if (0 <= cx && cx < N && 0 <= cy && cy < N && (maps[cx][cy] == 0 || maps[cx][cy] == 2)) {
                    if (maps[cx][cy] == 0) max_time = max(max_time, v.time + 1);
                    maps[cx][cy] = 3;
                    q.push_back({cx, cy, v.time+1});
                }
            } 
        }

        if (check_virus()) {
            total_time = min(total_time, max_time);
        }

    } while (next_permutation(combi.begin(), combi.end()));

    if (total_time == 1e9) cout << -1 << endl;
    else cout << total_time << endl;

    return 0;
}