#include <iostream>

using namespace std;
int t;
string ss;

bool func1(bool del_flag = false, int i = 0, int l = 0, int r = 1) {
    for (; i < ss.length() / 2; i++) {
        if (ss[i + l] != ss[ss.length() - r - i]) {
            if (del_flag) {
                return false; //다를 경우 바로 false 리턴

            } else {
                return func1(true, i, l + 1, r) || func1(true, i, l, r+1);
            }
        }
    }
    return true;
}

void sol() {
    int r;
    if (func1(true)) {
        r = 0; //회문

    } else if (func1()) {
        r = 1; //유사 회문

    } else {
        r = 2; //아무것도 아님
    };

    cout << r << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   cin >> t;
   while (t--) {
    cin >> ss;
    sol();
   }

    return 0;
}