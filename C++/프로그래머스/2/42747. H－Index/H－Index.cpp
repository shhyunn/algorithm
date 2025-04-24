#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//논문 n편 중, h번 이상 인용된 논문이 h편 이상이고, 나머지 논문이 h번 이하 인용되었다면, h의 최댓값이 h 인덱스임
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int i = 0;
    for (; i < citations.size(); i++) {
        if (citations[i] >= i + 1) continue;
        else {
            return i;
        }
    }
    
    return i;
}