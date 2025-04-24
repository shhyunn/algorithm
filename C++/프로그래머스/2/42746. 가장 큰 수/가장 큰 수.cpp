#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strNumbers;
    
    string answer = "";
    for (int n : numbers) {
        strNumbers.push_back(to_string(n));
    }
    
    sort(strNumbers.begin(), strNumbers.end(), compare);
    
    if (strNumbers[0] == "0") {
        return "0";
    }
    
    for (string s : strNumbers) {
        answer += s;
    }
    return answer;
}