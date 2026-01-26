#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

int find(int x) {
    if (arr[x] == x) return x;
    return arr[x] = find(arr[x]);
}

void sums(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a > b) {
        arr[a] = b;
    } else {
        arr[b] = a;
    }
    return;
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n+1,0);

    for (int i = 0; i < n+1; i++) {
        arr[i] = i;
    }

    int id, a, b;  
    for (int i = 0; i < m; i++) {
        cin >> id >> a >> b;

        if (id == 0) { //두 숫자가 속한 집합을 합치기
            sums(a, b);

        } else { //두 숫자가 같은 집합인지 확인하기
            if (find(a) == find(b)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }

        }
    }
    return 0;
}