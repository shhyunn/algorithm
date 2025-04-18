#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;
string A, B;
int l1, l2;
int dp[MAX][MAX];

int main() {
    cin>>A>>B;
    l1 = A.size();
    l2 = B.size();

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string res;
    int i = l1;
    int j = l2;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            res.push_back(A[i-1]);
            i--;
            j--;
        }
    }

    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    return 0;
}