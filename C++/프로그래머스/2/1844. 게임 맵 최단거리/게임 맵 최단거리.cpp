#include<vector>
#include <bits/stdc++.h>
using namespace std;
//캐릭터가 상대팀 진영에 도착하기 위해 지나가야 하는 개수의 최솟값
vector<vector<int>> visited;
int N; int M; int answer;
int move_x[4] = {0,0,-1,1};
int move_y[4] = {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    answer = 0;
    N = maps.size();
    M = maps[0].size();
    visited.resize(N, vector<int>(M, 0));
    
    deque<tuple<int, int, int>> stack;
    stack.push_back({0,0,1});
    visited[0][0] = 1;
    
    while (!stack.empty()) {
        auto [i,j,cnt] = stack.front(); stack.pop_front();
        
        if (i == N-1 && j == M-1) {
            answer = cnt;
            return cnt;
        }
        
        for (int s = 0; s < 4; s++) {
            int curr_i = i + move_x[s];
            int curr_j = j + move_y[s];
            
            if (0 <= curr_i && curr_i < N && 0 <= curr_j && curr_j < M && !visited[curr_i][curr_j] && maps[curr_i][curr_j] ==1) {
                stack.push_back({curr_i, curr_j, cnt+1});
                visited[curr_i][curr_j] = 1;
            }
        }
        
        
    }
    return -1;
}