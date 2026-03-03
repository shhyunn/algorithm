#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int R, C;
vector<vector<int>> maps;
vector<vector<int>> check;
queue<pair<int, int>> q;
int result = -1;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

void bfs() {
    int nx, ny;

    while (!q.empty()) {
        pair<int, int> a = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            nx = a.first + move_x[i];
            ny = a.second + move_y[i];

            if (0 > nx || nx >= R || 0 > ny || ny >= C) continue;
            if (maps[nx][ny] == 0 || check[nx][ny] > 0) continue;

            check[nx][ny] = check[a.first][a.second] + 1;
            result = max(result, check[nx][ny]);
            q.push({nx, ny});
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    maps.assign(R, vector<int>(C, 0));
    check.assign(R, vector<int>(C, 0));
    

    for (int i = 0; i < R; i++) {
        string tmp;

        cin >> tmp;

        for (int j = 0; j < C; j++) {
            if (tmp[j] == 'L') maps[i][j] = 1;
            else maps[i][j] = 0;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maps[i][j] == 1) {
                check[i][j] = 1;
                q.push({i, j});
                bfs();

                for (int k = 0; k < R; k++) {
                    for (int l = 0; l < C; l++) {
                        check[k][l] = 0; //초기화
                    }
                }
            }
        }
    }
    
    cout << result - 1 << endl;


    return 0;
    
}
