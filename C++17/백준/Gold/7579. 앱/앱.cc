#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long M;
vector<long long> memory_arr;
vector<long long> cost_arr;
vector<long long> dp;

int main() {
    cin >> N >> M;

    memory_arr.assign(N, 0);
    cost_arr.assign(N, 0);
    dp.assign(10001, 0); //비용 값 기준

    for (int i = 0; i < N; i++) {
        cin >> memory_arr[i];
    }

    long long sumCost = 0;

    for (int i = 0; i < N; i++) {
        cin >> cost_arr[i];
        sumCost += cost_arr[i];
    }

    for (int i = 0; i < N; i++) { //아이템 개수
        for (long long m = sumCost; m >= cost_arr[i]; m--) { //전체 가능한 cost에서 업데이트
            dp[m] = max(dp[m], dp[m-cost_arr[i]] + memory_arr[i]);
        }
    }

    for (int i = 0; i <= sumCost; i++) {
        if (dp[i] >= M) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}