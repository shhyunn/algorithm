#include <iostream>
#include <queue>
using namespace std;
#define MAX 10000010

int N;
long long dp[MAX]; //n번째 감소하는 수 저장

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //왼쪽자리가 항상 오른쪽자리보다 큰 숫자를 구하는 문제
    cin >> N;
    
    queue<long long> q;

    for (int i = 0; i < 10; i++) {
        q.push(i);
        dp[i] = i;
    }

    if (0 <= N && N <= 10) {
        cout << N << endl;
        return 0;
    }

    int idx = 10;

    //0,1,2,3,4,5,6,7,8,9
    while (idx <= N && !q.empty()) {
        long long number = q.front();
        q.pop();

        int last = number % 10;
        for (int i = 0; i < last; i++) {
            q.push(number*10+i);
            dp[idx++] = number*10+i;
        }
    }

    if (idx >= N && dp[N] != 0) cout << dp[N] << endl;
    else cout << -1 << endl;
    
    return 0;
}
