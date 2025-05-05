#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int v; int e;
vector<int> parent;

int find(int v) {
    if (parent[v] != v) {
        return parent[v] = find(parent[v]);
    } else {
        return v;
    }
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    cin >> v >> e;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;
    parent.resize(v+1);

    for (int i = 0; i < e; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        edges.push({c, a, b});
    }

    for (int i = 1; i < v + 1; i++) parent[i] = i;
    int answer = 0;

    while (!edges.empty()) {
        auto [cost, a, b] = edges.top(); edges.pop();
        if (find(a) != find(b)) {
            union_set(a,b);
            answer += cost;
        }
    }

    cout << answer << endl;

    return 0;
}