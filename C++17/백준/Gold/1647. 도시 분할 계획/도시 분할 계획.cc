#include <iostream>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
int n; int m;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    cin >> n >> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;
    parent.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        edges.push({c, a, b});
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    int max_weight = 0;
    int answer = 0;

   while (!edges.empty()) {
    auto [cost, a, b] = edges.top();
    edges.pop();

    if (find(a) != find(b)) {
        union_set(a,b);
        answer += cost;
        max_weight = max(max_weight, cost);
    }
   }
    answer -= max_weight;
    cout << answer << endl;

    return 0;
}