#include <bits/stdc++.h>

using namespace std;
//모든 차량이 한 번의 단속용 카메라를 만나도록 하려면 최소 몇 대의 카메라가 필요한가??
//나간 지점 기준으로 정렬 + 처음 나간 지점에 카메라 설치

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);
    
    int curr_end = -30001;
    int answer = 0;
    for (auto& r : routes) {
        int start = r[0];
        int end = r[1];
        
        if (curr_end < start) {
            answer++;
            curr_end = end;
            continue;
        }
        
        
    }
    return answer;
}