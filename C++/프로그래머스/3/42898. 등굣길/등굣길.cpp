#include <bits/stdc++.h>
#define MAX_NUM 1000000007
using namespace std;
//최단 경로의 개수를 -로 나눈 나머지, 물웅덩이는 피해서 가야함
int solution(int m, int n, vector<vector<int>> puddles) {
    
    int answer = 0;
    
    vector<vector<int>> maps;
    maps.resize(m, vector<int>(n, 0));
    for (auto& p : puddles) {
        maps[p[0]-1][p[1]-1] = -1; //접근 불가
    }
    
    maps[0][0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (maps[i][j] == -1) {maps[i][j] = 0; continue;}
            
            if (i > 0 && maps[i-1][j] != -1) maps[i][j] = (maps[i][j] + maps[i-1][j] % MAX_NUM);
            if (j > 0 && maps[i][j-1]) maps[i][j] = (maps[i][j] + maps[i][j-1]) % MAX_NUM;
        }
     }
    return maps[m-1][n-1];
}