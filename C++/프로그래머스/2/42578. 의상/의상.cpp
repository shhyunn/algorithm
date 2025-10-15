#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> maps;
    
    for (auto& c : clothes) {
        maps[c[1]]++;
    }
    
    for (auto& [key, value] : maps) {
        cout << value << "\n";
        answer *= (value + 1);
    }
    cout << answer << "answer";
    answer--;
    
    return answer;
}