#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> s1 = {1,2,3,4,5};
    vector<int> s2 = {2,1,2,3,2,4,2,5};
    vector<int> s3 = {3,3,1,1,2,2,4,4,5,5};
    
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == s1[i % 5]) a1++;
        if (answers[i] == s2[i % 8]) a2++;
        if (answers[i] == s3[i % 10]) a3++;
    }
    
    int max_value = max({a1, a2, a3});
    if (a1 ==max_value) answer.push_back(1);
    if (a2 == max_value) answer.push_back(2);
    if (a3 == max_value) answer.push_back(3);
    return answer;
}