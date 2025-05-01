#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
vector<vector<int>> lands;
vector<int> ccount;
vector<bool> j_visited;
vector<vector<bool>> visited;
int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};
int row;
int col;

void bfs(int i, int j) {
    fill(j_visited.begin(), j_visited.end(), false); //false로 초기화
    j_visited[j] = true;
    
    deque<pair<int, int>> stack;
    
    stack.push_back({i,j});
    visited[i][j] = true;
    j_visited[j] = true;
    int cnt = 0;
    
    while (!stack.empty()) {
        auto [x,y] = stack.front();
        j_visited[y] = true;
        stack.pop_front();
        cnt++;
        
        for (int i = 0; i < 4; i++) {
            int cx = x + move_x[i];
            int cy = y + move_y[i];
            
            if (0 <= cx && cx < row && 0 <= cy && cy < col && !visited[cx][cy] && lands[cx][cy] == 1) {
                visited[cx][cy] = true;
                stack.push_back({cx, cy});
            }
        }
    }
    
    for (int k = 0; k < col; k++) {
        if (j_visited[k]) {
            ccount[k] += cnt;
        }
    }
}

int solution(vector<vector<int>> land) {
    lands = land;
    row = land.size();
    col = land[0].size();
    ccount.resize(col, 0);
    j_visited.resize(col, false);
    visited.resize(row, vector<bool>(col, false));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visited[i][j] && lands[i][j] == 1) {
                bfs(i,j); //i,j로 bfs 시작
            }
        }
    }
    
    int answer = *max_element(ccount.begin(), ccount.end());
    
    return answer;
}