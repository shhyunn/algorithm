#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int money_length = money.size();
    vector<int> dp1(money_length, 0); //첫 집을 턴 경우
    vector<int> dp2(money_length, 0); //첫 집을 털지 않은 경우
    
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    dp2[1] = money[1];
    
    for (int i = 2; i < money_length - 1; i++) {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    for (int i = 2; i < money_length; i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    int answer = max(dp1[money_length - 2], dp2[money_length-1]);
    return answer;
}