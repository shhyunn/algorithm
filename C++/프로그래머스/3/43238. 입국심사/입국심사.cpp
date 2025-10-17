#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 1;
    long long end = (long long)*max_element(times.begin(), times.end()) * n;
    
    long long mid;
    long long answer = LLONG_MAX;
    while (start <= end) {
        mid = (start + end) / 2;
        long long cnt = 0;
        for (int& t : times) {
            cnt += (mid / t);
        }
        
        if (cnt >= n) {
            end = mid - 1;
            answer = min(answer, mid);
        } else {
            start = mid + 1;
        }
    }
    return answer;
}