#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, bool>> v(N * 2, {0, false}); //현재 로봇 있는지 여부

    for(int i = 0; i < N * 2; i++) {
        cin >> v[i].first; 
    }
        

    int upIdx = 0; // 올리는 위치
    int ans = 1;

    while(true){
        //벨트 회전
        upIdx = (upIdx + (N * 2) - 1) % (N * 2);
        int downIdx = (upIdx + N - 1) % (N * 2); // 내리는 위치

        if (v[downIdx].second)
            v[downIdx].second = false; // 로봇있으면 내림

        for (int i = upIdx + N - 1; i >= upIdx; i--){ //먼저 올린 로봇부터 확인
            int nowIdx = i % (N * 2); // i가 2N보다 클 수 있음
            int nextIdx = (nowIdx + 1) % (N * 2); //이동할 인덱스

            if (v[nowIdx].second && (!v[nextIdx].second && v[nextIdx].first > 0)) { //현재 로봇이 있고, 다음 칸에 로봇이 없고, 내구도가 1 이상일 경우
                v[nowIdx].second = false; //현재 로봇 제거
                v[nextIdx].first--; //내구도 감소
                v[nextIdx].second = true; //로봇 이동
            }
        }

        if (v[downIdx].second) //내리는 인덱스에 로봇이 있다면 없애기
            v[downIdx].second = false;

        // 새로운 로봇 올리기
        if(v[upIdx].first > 0){ //내구도가 1 이상이라면
            v[upIdx].first--;
            v[upIdx].second = true;
        }

        // 내구도 0 카운트
        int cnt = 0;
        for(auto elem : v){
            if(elem.first == 0)
                cnt++;
        }

        if(cnt >= K) break; //내구도 0인 칸이 K개 이상일 경우 종료
        ans++; //단계 증가
    }
    cout << ans << '\n';
	return 0;
}
