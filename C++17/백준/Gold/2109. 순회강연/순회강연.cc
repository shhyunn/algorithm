#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int n, d, p;
using namespace std;
vector<pair<int, int>> arr;

struct cmp {
    bool operator() (pair<int, int>& a, pair<int ,int>& b) {
        return a.first < b.first; //큰게 탑, 날짜 큰게 탑
    }
};

int main() {
    cin >> n;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        pq.push({d, p});
    }

    priority_queue<int, vector<int>> st;
    int answer = 0;
    int day = 0;
    if (n != 0) {
        auto p = pq.top(); pq.pop();
        day = p.first;
        st.push(p.second);

        while (!pq.empty()) {
            auto k = pq.top(); pq.pop();
            if (k.first != day) {
                int diff = day - k.first;

                while (!st.empty() && diff--) {
                    int a1 = st.top(); st.pop();
                    answer += a1;
                }

                day = k.first;
            }
            st.push(k.second);
        }

        for (int i = 0; i < day; i++) {
            int a2 = st.top(); st.pop();
            answer += a2;
        }
    }

    cout << answer << endl;

    

    return 0;
}