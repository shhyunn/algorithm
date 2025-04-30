#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값
//level: 숙련도
//퍼즐을 틀리고, 해당 퍼즐을 다시 풀음
//숙련도 이분탐색?, diffs의 최솟값, diffs의 최댓값

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int min_level = *min_element(diffs.begin(), diffs.end());
    int max_level = *max_element(diffs.begin(), diffs.end());
    
    cout << min_level << max_level;
    int size = diffs.size();
    
    while (min_level <= max_level) {
        int mid = (min_level + max_level) / 2;
        long long curr = 0;
        for (int i = 0; i < size; i++) {
            if (diffs[i] <= mid) {
                curr += (long long)times[i];
            } else {
                curr += (long long)(times[i - 1] + times[i]) * (diffs[i] - mid);
                curr += (long long)times[i];
            }
        }
        
        if (curr > limit) {
            min_level = mid + 1;
        } else {
            max_level = mid - 1;
        }
    }
    return min_level;
}