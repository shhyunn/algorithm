#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i < yellow + 1; i++) {
        if (yellow % i != 0) {
            continue;
        }
        
        int j = yellow / i;
        if ((j+2) * (i+2) == yellow + brown) {
            answer.push_back(j+2);
            answer.push_back(i+2);
            return answer;
        }
    }
    return answer;
}