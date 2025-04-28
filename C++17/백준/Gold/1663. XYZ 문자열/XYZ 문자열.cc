#include <iostream>
#include <string>
using namespace std;

int Q; int N;
string base[4];
long long dp[101];
long long answer = 0;
long long cnt[101][3];

//메인 아이디어 - 구하고자 하는 것은 n단계 수의 전체 길이, 특정 자리의 알파벳, 알파벳의 개수
//누적 계산식을 이용해 특정 자리 알파벳과 전체 길이는 쉽게 구하기 가능
//특정 자리의 알파벳은 이분 탐색으로 찾기 - k번쨰 수가 n-3의 길이보다 작다면 n-3단계로 이동, n-3보다 크다면 n-2단계로 이동

char solve(long long k, long long n) { // n번째 수에서 k번째 알파벳은?
    if (n <= 3) return base[n][k-1];

    if (dp[n-3] >= k) return solve(k, n - 3); //왼쪽에 위치한다면, n-3단계로 이동
    else return solve(k - dp[n-3], n - 2);

}

int main() {
    cin >> Q;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    base[1] = "X";
    base[2] = "YZ";
    base[3] = "ZX";

    cnt[1][0] = 1;
    cnt[2][1] = cnt[2][2] = 1;
    cnt[3][0] = cnt[3][2] = 1;

    for (int i = 4; i < N + 1; i++) {
        dp[i] = dp[i-2] + dp[i-3];
        for (int j = 0; j < 3; j++) {
            cnt[i][j] = cnt[i-2][j] + cnt[i-3][j];
        }
    }

    if (Q == 1) {
        cout << dp[N];
    } else if (Q == 3) {
        char K;
        cin >> K;
        cout << cnt[N][K - 'X'];
    } else {
        long long K;
        cin >> K;
        cout << solve(K, N);
    }

    return 0;
}