#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> arr;
int res[3] = {0,0,0};


bool check(int x, int y, int k) {
    int v = arr[x][y];

    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++) {
            if (v != arr[i][j]) return false;
        }
    }
    res[v+1]++;
    return true;
}
void func(int x, int y, int k) {
    bool res = check(x,y,k);
    if (res) {
        return; //모두 같은 숫자라면 바로 return
    }
    int div = k / 3;
    for (int i = x; i < x + k; i+=div) {
        for (int j = y; j < y + k; j+= div) {
            func(i, j, div);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int v = n / 3;

    func(0,0,n);

    cout << res[0] << "\n" << res[1] << "\n" << res[2] << endl;

    
    return 0;
}