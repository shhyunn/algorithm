#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int answer;
int answer_cnt;

vector<vector<int>> maps;
vector<vector<bool>> visited;
int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

deque<pair<int, int>> func1(deque<pair<int, int>> ss) {
    deque<pair<int, int>> st1 = ss;
    deque<pair<int ,int>> st2;

    while (!st1.empty()) {
        pair<int, int> a1 = st1.front(); st1.pop_front();
        maps[a1.first][a1.second] = 0;

        for (int i = 0; i < 4; i++) {
            int mx = a1.first + move_x[i];
            int my = a1.second + move_y[i];

            if (0 <= mx && mx < N && 0 <= my && my < M && !visited[mx][my]) {
                visited[mx][my] = true;
                if (maps[mx][my] == 1) {
                    st2.push_back({mx, my});
                }
                else st1.push_back({mx, my});
            }
        }
    }

    return st2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    maps.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
        }
    }

    deque<pair<int, int>> st;
    deque<pair<int, int>> main_st;
    

    st.push_back({0,0});
    visited[0][0] = true;

    while (!st.empty()) {
        pair<int, int> tmp = st.front(); st.pop_front();

        for (int i = 0; i < 4; i++) {
            int mx = tmp.first + move_x[i];
            int my = tmp.second + move_y[i];

            if (0 <= mx && mx < N && 0 <= my && my < M && !visited[mx][my]) {
                visited[mx][my] = true;
                if (maps[mx][my] == 1) {
                    main_st.push_back({mx, my});
                }
                else st.push_back({mx, my});
            }
        }
    }

    bool is_continue = true;

    while (is_continue) {
        answer_cnt++;
        answer = main_st.size();
        main_st = func1(main_st);

        if (main_st.size() == 0){
            is_continue = false;
        }
    }

    cout << answer_cnt << "\n" << answer << endl;

    return 0;
}