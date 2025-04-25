#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    int curr = k;
    
    for (int i = 0; i < number.length(); i++) {
        if (stack.empty()) {
            stack.push_back(number[i]);
            continue;
        }
        
        while (!stack.empty() && stack.back() < number[i] && curr > 0) {
            stack.pop_back();
            curr--;
        }

        stack.push_back(number[i]);

    }
    
    while (curr > 0) {
        stack.pop_back();
        curr--;
    }
    
    for (char& s :stack) {
        answer += s;
    }
    
    return answer;
}