#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct DateInfo {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<DateInfo> arr;

    for(int i = 0; i < N; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;

        int start = sm * 100 + sd;
        int end = em * 100 + ed;

        arr.push_back({start, end});
    }

    // start 오름차순, start 같으면 end 내림차순
    sort(arr.begin(), arr.end(), [](const DateInfo& a, const DateInfo& b) {
        if(a.start == b.start) return a.end > b.end;
        return a.start < b.start;
    });

    int cur = 301;      // 3월 1일
    int target = 1201;  // 12월 1일
    int cnt = 0;
    int i = 0;

    while (cur < target) {
        int maxEnd = cur;

        // cur 이전에 시작하는 꽃들 중 가장 멀리까지 가는 end 찾기
        while (i < N && arr[i].start <= cur) {
            maxEnd = max(maxEnd, arr[i].end);
            i++;
        }

        // 확장 불가능하면 실패
        if(maxEnd == cur) {
            cout << 0 << "\n";
            return 0;
        }

        cur = maxEnd;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}