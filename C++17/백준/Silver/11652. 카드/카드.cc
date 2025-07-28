#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N;
map<long long, int> dic;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    long long x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        dic[x]++;
    }

    long long ans, max = 0;
    
    for (auto i = dic.begin(); i != dic.end(); i++) {
        if (i->second > max) {
            ans = i->first;
            max = i->second;
        } else if (i ->second == max){
            if (ans > i->first) ans = i->first;
        }
    }

    cout << ans << endl;
    
    return 0;
}