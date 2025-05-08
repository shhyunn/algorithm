#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool sorting(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; int K; int M; int V; int C;
    vector<pair<int , int>> stack1;
    vector<int> stack2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap; //보석 가치 기준 내림차순

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        stack1.push_back({M, V});
    }

    sort(stack1.begin(), stack1.end(), sorting); //보석 무게로 내림차순 정렬

    for (int i = 0; i < K; i++) {
        cin >> C;
        stack2.push_back(C);
    }

    sort(stack2.begin(), stack2.end(), greater<int>()); //가방 무게로 내림차순으로 정렬
    long long answer = 0;

    while (!stack1.empty() && !stack2.empty()) { //보석이 있을 때까지
        int curr = stack2.back(); //현재 가방

        while (!stack1.empty() && stack1.back().first <= curr) { //현재 가방에 담을 수 있다면
            auto s = stack1.back();
            heap.push(s);
            stack1.pop_back();
        }

        if (!heap.empty()) {
            auto h = heap.top(); 
            heap.pop();
            answer += (long long)h.second;
        }
        stack2.pop_back();
    }

    while (!heap.empty() && !stack2.empty()) {
        auto h = heap.top(); heap.pop();
        stack2.pop_back();
        answer += (long long)h.second;
    }

    cout << answer << endl;
    
    return 0;
}