#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        auto it = lower_bound(A.begin(), A.end(), num);

        if (it == A.end()) {
            A.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << A.size() << endl;

    
    return 0;
}