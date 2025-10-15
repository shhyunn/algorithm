#include <string>
#include <vector>
#include <cmath> 
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> stack;
    int psize = progresses.size();
    
    for (int i = 0; i < psize; i++) {
        int d = ceil((double)(100 - progresses[i]) / speeds[i]);
        if (stack.empty()) {
            stack.push_back(d);
            continue;
        } 
        if (stack.front() >= d) {
            stack.push_back(d);
            continue;
        }
        
        int curr = d;
        int curr_size = 0;
        while (!stack.empty() && stack.front() < d) {
            stack.pop_back();
            curr_size++;
        }
        stack.push_back(curr);
        answer.push_back(curr_size);
    }
    
    if (!stack.empty()) {
        answer.push_back(stack.size());
    }
    
    return answer;
}