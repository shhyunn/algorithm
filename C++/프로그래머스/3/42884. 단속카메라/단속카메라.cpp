#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//모든 차량이 한 번의 단속용 카메라를 만나도록 하려면 최소 몇 대의 카메라가 필요한가??
//나간 지점 기준으로 정렬 + 처음 나간 지점에 카메라 설치

bool sorting(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), sorting);
    int cnt = 0;
    int curr = -1;
    
    for (auto& r : routes) {
        if (curr == -1) {
            cnt++;
            curr = r[1];
            continue;
        }
        
        if (r[0] <= curr) continue;
        else {
            cnt++;
            curr = r[1];
            continue;
        }
    }
    return cnt;
}