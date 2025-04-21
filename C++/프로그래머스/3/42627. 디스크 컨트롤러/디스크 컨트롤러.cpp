#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;
//소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것
priority_queue<tuple<int, int, int>> heap;
unordered_map<int, vector<int>> dic;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    for (int i = 0; i < size; i++) {
        dic[jobs[i][0]].push_back(i); //작업 번호 넣기
    }
    int sec = 0;
    int curr = 0;
    
    while (!dic.empty() or !heap.empty()) {
        if (curr > 0) {
            curr--;
        }
        
        if (dic.find(sec) != dic.end()) {
            int dic_size = dic[sec].size();
            for (int i = 0; i < dic_size; i++) {
                int v = dic[sec][i];
                heap.push({-jobs[v][1], -sec, -v});
            }
            dic.erase(sec);
        }
        
        if (curr == 0 && !heap.empty()) {
             auto [a, b, c] = heap.top();
            heap.pop();
            answer += (sec -a + b);
            curr = -a;
        }
        
        sec++;  
        
    }
    answer = answer / size;
    return answer;
}