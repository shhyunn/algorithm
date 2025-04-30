#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기, 
//오프닝 구간인 경우 오프닝이 끝나는 위치로 이동
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    //mm:ss
    string answer = "";
    int curr = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    int open_time = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    int close_time = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));
    
    int video_time = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    if (open_time <= curr && curr <= close_time) {
            curr = close_time;
        }
    
    for (auto& command : commands) {
        if (command == "prev") {
            curr = max(0, curr - 10);
            
        } else if (command == "next") {
            curr = min(video_time, curr + 10);
        }
        
        if (open_time <= curr && curr <= close_time) {
            curr = close_time;
        }
    }
    
    int mm = curr / 60;
    if (mm < 10) {
        answer += "0";
        answer += to_string(mm);
    } else {
        answer += to_string(mm);
    }
    
    int ss = curr % 60;
    answer += ":";
    
    if (ss < 10) {
        answer += "0";
        answer += to_string(ss);
    } else {
        answer += to_string(ss);
    }
    
    return answer;
}