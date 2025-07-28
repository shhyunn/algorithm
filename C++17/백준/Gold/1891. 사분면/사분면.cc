#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;
int n;
string nd;
long long k;
long long curr_x; long long curr_y;
long long move_x, move_y;

string res;

void func(long long x, long long y, int i, long long k) {
    if (i == n) {
        curr_x = x;
        curr_y = y;
        return;
    }

    int v = nd[i] - '0';
    if (v == 1) {
        func(x+k/2, y, i+1, k/2);
    } else if (v == 2) {
        func(x, y,i+1, k/2);
    } else if (v == 3) {
        func(x, y+k/2, i+1, k/2);
    } else {
        func(x+k/2, y+k/2, i+1, k/2);
    }
}

void find(long long x, long long y, int i, long long k) {
    if ( i == n) return;

    if (0 <= x && x < k/2) {
        if (0 <= y && y < k/2) {
            res += "2";
        } else if ( k/2 <= y && y < k) {
            res += "3";
            y -= k/2;
        } else {
            res = "-1";
            return;
        }
    } else if ( k/2 <= x && x < k) {
        if (0 <= y && y < k/2) {
            res += "1";
            x -= k/2;
        } else if ( k/2 <= y && y < k) {
            res += "4";
            x -= k/2;
            y -= k/2;
        } else {
            res = "-1";
            return;
        }
    } else {
        res = "-1";
        return;
    }

    find(x, y, i+1, k/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> nd;
    k = pow(2,n);
    func(0, 0, 0, k); //i,j,0번째, k가 최대

    cin >> move_x >> move_y;

    long long rx = curr_x + move_x;
    long long ry = curr_y - move_y;

    find(rx, ry, 0, k);

    cout << res << endl;
    
    return 0;
}
