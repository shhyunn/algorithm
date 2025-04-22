#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int> min_heap;
unordered_map<int, bool> number_dic;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    int ss;
    for (string s : operations) {
        if (s[0] == 'I') {
            ss = stoi(s.substr(2));
            number_dic[ss] = true;
            max_heap.push(ss);
            min_heap.push(-ss); //부호 반전하여 삽입
            
        } else if (s[0] == 'D' && s[2] == '1') {
            //최댓값 삭제
            while (!max_heap.empty() &&!number_dic[max_heap.top()]) {
                max_heap.pop(); //현재 숫자 삭제
            }
            if (max_heap.empty()) continue;
            number_dic[max_heap.top()] = false; //삭제
            max_heap.pop(); //삭제
            
        } else {
            while (!min_heap.empty() && !number_dic[-min_heap.top()]) {
                min_heap.pop();
            }
            if (min_heap.empty()) continue;
            
            number_dic[-min_heap.top()] = false;
            min_heap.pop(); //삭제
        }
    }
    
   
    
    while (!max_heap.empty()) {
        if (number_dic[max_heap.top()]) {
            answer[0] = max_heap.top();
            break;
        } else {
            max_heap.pop();
        }
    }
        
    while (!min_heap.empty()) {
        if (number_dic[-min_heap.top()]) {
            answer[1] = -min_heap.top();
            break;
        } else {
            min_heap.pop();
        }
    }
                   
                   
                   
                   
    return answer;
}