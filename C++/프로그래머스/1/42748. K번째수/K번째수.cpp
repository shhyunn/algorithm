#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//2번째부터 5번째까지 자르고, 정렬, k번째 수
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const auto& command : commands) {
        vector<int> temp(array.begin() + command[0] -1, array.begin() + command[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[command[2]-1]);
    }
    
    return answer;
}