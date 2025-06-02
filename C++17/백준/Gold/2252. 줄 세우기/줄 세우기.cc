#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N; int M;
vector<vector<int>> graph;
vector<int> in_degree;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    graph.resize(N+1);
    in_degree.resize(N+1);
    int a; int b;
    for (int i = 1; i < M+1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    deque<int> stack;

    for (int i = 1; i < N+1; i++) {
        if (in_degree[i] == 0) stack.push_back(i);
    }

    while (!stack.empty()) {
        int v = stack.front(); stack.pop_front();

        cout << v << " ";

        for (auto k : graph[v]) {
            in_degree[k]--;
            if (in_degree[k] == 0) stack.push_back(k);
        }
    }

    cout << endl;
    
    return 0;
}