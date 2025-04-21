#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> stack;
vector<int> sequence;

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    sequence.resize(size);
    
    for (int i = 0; i < size; i++) {
        stack.push(i);
    }
    
    int seq = 1;
    
    while (!stack.empty()) {
        int v = stack.front();
        
        if (priorities[v] == *max_element(priorities.begin(), priorities.end())) {
            //priorities가 가장 높을 경우
            stack.pop(); //스택에서 삭제
            priorities[v] = 0;
            sequence[v] = seq;
            seq++;
            
        } else {
            stack.pop();
            stack.push(v); //다시 넣기
        }
    }
    
    return sequence[location];
}