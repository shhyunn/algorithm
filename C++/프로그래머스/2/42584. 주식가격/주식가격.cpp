#include <string>
#include <vector>

using namespace std;
//가격이 떨어지지 않은 기간이 몇 초인가??
//스택에서 마지막 요소와 비교해서 계속 증가하는 경우 쌓기, 
vector<int> stack;

vector<int> solution(vector<int> prices) {
    
    int size = prices.size();
    vector<int> answer = vector<int>(size);
    int v = 0;
    for (int i = 0; i < size; i++) {
        if (stack.empty()) {
            stack.push_back(i);
            continue;
        }
        if (prices[stack.back()] <= prices[i]) {
            stack.push_back(i);
            continue;
            
        } else { //작다면, 가격이 떨어졌다면
            while (!stack.empty() && prices[stack.back()] > prices[i]) {
                v = stack.back();
                stack.pop_back();
                answer[v] = i - v;
            }
            stack.push_back(i);
        }
    }
    
    while (!stack.empty()) {
        v = stack.back();
        stack.pop_back();
        answer[v] = size - v - 1;
    }
    return answer;
}