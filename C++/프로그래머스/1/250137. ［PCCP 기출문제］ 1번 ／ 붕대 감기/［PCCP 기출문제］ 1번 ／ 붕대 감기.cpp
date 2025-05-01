#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//t초동안 붕대를 감으며 1초마다 x만큼의 최력 회복

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curr_health = health;
    int prev = 0; //이전 공격 받은 시간
    
    for (auto& attack : attacks) {
        int attack_time = attack[0];
        int attack_size = attack[1];
        
        int tmp = attack_time - prev - 1;
        curr_health = min(health, curr_health + tmp * bandage[1] + (tmp / bandage[0]) * bandage[2]);
        prev = attack_time;
        curr_health -= attack_size;
        
        if (curr_health <= 0) return -1;
        
        
    }
    
    return curr_health;
}