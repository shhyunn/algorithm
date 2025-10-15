#include <bits/stdc++.h>

using namespace std;
//모든 음식의 스코빌 지수가 K이상이 될 때까지 반복하여 섞음, 가장 낮은 두 개의 음식을 계속해서 섞음, queue, 섞는 횟수 리턴
priority_queue<int> heap;

int solution(vector<int> scoville, int K) {
    int answer;
    for (int s : scoville) {
        heap.push(-1 * s); //최소 힙 만들기
    }
    
    bool available = true;
    int cnt = 0;
    cout << heap.top();
    
    while (-heap.top() < K) {
        if (heap.size() < 2) {
            available = false;
            break;
        }
        
        int new_v = -heap.top();
        heap.pop();
        new_v += (-heap.top() * 2);
        heap.pop();
        
        heap.push(-new_v);
        cnt++;
    }
    
    if (available) return cnt;
    return -1;

}