#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> stack;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack.push({0,0}); //0번째에서 시작
    
    while (!stack.empty()) {
        auto [i, total] = stack.front();
        stack.pop();
        
        if (i == numbers.size()) {
            if (total == target) answer += 1;
            continue;
        }
        
        stack.push({i+1, total + numbers[i]});
        stack.push({i+1, total - numbers[i]});
    }
        
    return answer;
}