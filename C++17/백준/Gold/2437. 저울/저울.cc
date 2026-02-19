#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
int sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < n; i++) {
        if (v[i] > sum + 1) break;
        sum += v[i];
    }

    cout << sum + 1 << endl;

   
    return 0;
}