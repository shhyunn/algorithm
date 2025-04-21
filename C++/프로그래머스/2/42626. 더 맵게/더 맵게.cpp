#include <string>
#include <vector>
#include <queue>

using namespace std;
//모든 음식의 스코빌 지수가 K이상이 될 때까지 반복하여 섞음, 가장 낮은 두 개의 음식을 계속해서 섞음, queue, 섞는 횟수 리턴
priority_queue<int> heap;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int size = scoville.size();
    
    for (int i = 0; i < size; i++) {
        heap.push(-scoville[i]);//최대힙이 기본이므로 - 곱함
    }
    int a = 0;
    int b = 0;
    int c = 0;
    bool available = true;
    
    while (-heap.top() < K) {
        if (heap.size() < 2) {
            available = false;
            break;
        };
        
        a = -heap.top(); 
        heap.pop();
        b = -heap.top();
        heap.pop();
        c = a + (b * 2);
        heap.push(-c);
        answer += 1;
        
    }
    if (available) return answer;
    else return -1;

}