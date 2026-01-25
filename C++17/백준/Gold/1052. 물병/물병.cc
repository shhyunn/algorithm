#include <iostream>

using namespace std;

int n, k;
int cnt, answer;

int func1() {
    int tmp = n;
    int ans = 0;
    while (tmp > 0) {
        ans += (tmp & 1);
        tmp >>= 1;
    }
    return ans;
}

int main() {
    cin >> n >> k;

    while (func1() > k) {
        n += 1;
        answer += 1;
    }

    cout << answer << endl;
    
    return 0;
}