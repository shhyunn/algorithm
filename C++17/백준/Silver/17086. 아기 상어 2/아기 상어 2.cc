#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int N, M;
vector<vector<int>> maps;
vector<vector<int>> counting;
int move_x[8] = {-1,-1,-1,0,0,1,1,1};
int move_y[8] = {-1,0,1,-1,1,-1,0,1};
int max_cnt = 0;

void bfs(int x, int y) {

    deque<tuple<int, int, int>> stack;

    stack.push_back({x, y, 0});

    while (!stack.empty()) {
        auto [i, j, cnt] = stack.front(); stack.pop_front();

        for (int m = 0; m < 8; m++) {
            int cx = i + move_x[m];
            int cy = j + move_y[m];

            if (0 <= cx && cx < N && 0 <= cy && cy < M && counting[cx][cy] > cnt + 1 && maps[cx][cy] == 0) {
                counting[cx][cy] = cnt + 1;
                stack.push_back({cx, cy, cnt+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    maps.resize(N, vector<int>(M, 0));
    counting.resize(N, vector<int>(M, 101)); //101로 초기화

    deque<pair<int, int>> stack;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 1) {
                stack.push_back({i,j}); //아기상어 있는 칸
            } 
        }
    }

    while (!stack.empty()) {
        auto [x,y] = stack.front(); stack.pop_front();
        bfs(x,y);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maps[i][j] == 1) continue;
            max_cnt = max(max_cnt, counting[i][j]);
        }
    }

    cout << max_cnt << endl;
    return 0;
}