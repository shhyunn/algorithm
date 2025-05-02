#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int rows; int cols; 
int answer = 10000;
int move_x[4] = {0,0,-1,1};
int move_y[4] = {-1,1,0,0};

vector<vector<bool>> red_visited;
vector<vector<bool>> blue_visited;

int red_x; int red_y; int blue_x; int blue_y;

vector<vector<int>> mazes;

void backtracking(int rx, int ry, int bx, int by, int cnt) {
    if (mazes[rx][ry] == 3 && mazes[bx][by] == 4) {
        answer = min(answer, cnt);
        return;
    }
    int rcx; int rcy; int bcx; int bcy;
    bool moved_red = mazes[rx][ry] != 3;
    bool moved_blue = mazes[bx][by] != 4;
    
    if (moved_red) {
        for (int i = 0; i < 4; i++) {//4방향 고려
            rcx = rx + move_x[i];
            rcy = ry + move_y[i];

            if (0 <= rcx && rcx < rows && 0 <= rcy && rcy < cols && !red_visited[rcx][rcy] && mazes[rcx][rcy] != 5) {
                if (!moved_blue && rcx == bx && rcy == by) continue;
                red_visited[rcx][rcy] = true;
                if (moved_blue) {
                    for (int j = 0; j < 4; j++) {
                        bcx = bx + move_x[j];
                        bcy = by + move_y[j];
                        
                        if (0 <= bcx && bcx < rows && 0 <= bcy && bcy < cols && !blue_visited[bcx][bcy] && mazes[bcx][bcy] != 5) {
                            if (rcx == bcx && rcy == bcy) continue;
                            if (rcx == bx && rcy == by && bcx == rx && bcy == ry) continue;
                            blue_visited[bcx][bcy] = true;
                            backtracking(rcx, rcy, bcx, bcy, cnt+1);
                            blue_visited[bcx][bcy] = false;
                        }
                    }
                } else {
                    backtracking(rcx, rcy, bx, by, cnt+1);
                }
                red_visited[rcx][rcy] = false;
            }
        }  
    } else { //못 움직일 경우
        for (int j = 0; j < 4; j++) { //파란색은 움직일 수 있는 경우
            bcx = bx + move_x[j];
            bcy = by + move_y[j];
                        
            if (0 <= bcx && bcx < rows && 0 <= bcy && bcy < cols && !blue_visited[bcx][bcy] && mazes[bcx][bcy] != 5) {
                if (rx == bcx && ry == bcy) continue;
                blue_visited[bcx][bcy] = true;
                backtracking(rx, ry, bcx, bcy, cnt+1);
                blue_visited[bcx][bcy] = false;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    mazes = maze;
    rows = maze.size();
    cols = maze[0].size();
    
    //빨간 수레 이동 칸 1, 파란 수레 이동 칸 2
    red_visited.resize(rows, vector<bool>(cols, false));
    blue_visited.resize(rows, vector<bool>(cols, false));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mazes[i][j] == 1) {
                red_visited[i][j] = true;
                red_x = i; red_y = j;
            }
            
            if (mazes[i][j] == 2) {
                blue_visited[i][j] = true;
                blue_x = i; blue_y = j;
            }
        }
    }
    
    backtracking(red_x, red_y, blue_x, blue_y, 0);
    
    if (answer == 10000) return 0;
    return answer;
}