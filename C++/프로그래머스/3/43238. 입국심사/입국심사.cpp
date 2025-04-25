#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * (long)n;
    long long answer = right;
    long long tmp;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        tmp = 0;
        for (auto& t : times) {
            tmp += (mid / t);
        }
        
        if (n <= tmp) {
            answer = min(answer, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}