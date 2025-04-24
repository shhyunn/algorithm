#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    
    for (auto& size : sizes) {
        if (size[0] > size[1]) {
            w = max(w, size[0]);
            h = max(h, size[1]);
        } else {
            w = max(w, size[1]);
            h = max(h, size[0]);
        }
       
    }
    
    answer = w * h;
    return answer;
}