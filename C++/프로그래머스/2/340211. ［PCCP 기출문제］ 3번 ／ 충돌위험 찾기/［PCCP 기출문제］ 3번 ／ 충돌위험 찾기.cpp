#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<vector<int>>> result(101, vector<vector<int>>(101, vector<int>(20001, 0)));
    
    for (auto& route : routes) {
        int route_len = route.size();
        int prev_x = points[route[0]-1][0];
        int prev_y = points[route[0]-1][1];
        int cnt = 0;
        result[prev_x][prev_y][cnt]++;
        if (result[prev_x][prev_y][cnt] == 2) answer++;
        
        for (int i = 1; i < route_len; i++) {
            int curr_x = points[route[i]-1][0];
            int curr_y = points[route[i]-1][1];
            
            while (prev_x != curr_x) {
                cnt++;
                
                if (prev_x < curr_x) prev_x++;
                else prev_x--;
                result[prev_x][prev_y][cnt]++;
                
                if (result[prev_x][prev_y][cnt] == 2) answer++;
            }
            
            while (prev_y != curr_y) {
                cnt++;
                
                if (prev_y < curr_y) prev_y++;
                else prev_y--;
                result[prev_x][prev_y][cnt]++;
                
                if (result[prev_x][prev_y][cnt] == 2) answer++;
            }
        }
    }
    
    return answer;
}