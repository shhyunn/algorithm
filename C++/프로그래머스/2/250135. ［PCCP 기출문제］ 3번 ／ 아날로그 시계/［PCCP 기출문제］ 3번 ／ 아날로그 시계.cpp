#include <iostream>
#include <cmath> 

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    // 시작시간과 끝시간을 초 단위로 변환
    int startTime = h1 * 3600 + m1 * 60 + s1;
    int endTime = h2 * 3600 + m2 * 60 + s2;

    // 00시 또는 12시 정각일 경우 미리 카운팅
    if (startTime == 0 * 3600 || startTime == 12 * 3600) {
        answer++;
    }

    while (startTime < endTime) {
        // 현재 시각 각도 계산
        double hCurAngle = fmod(startTime / 120.0, 360.0);
        double mCurAngle = fmod(startTime / 10.0, 360.0);
        double sCurAngle = fmod(startTime * 6.0, 360.0);

        // 다음 시각 각도 계산 (0도 대신 360도로 보정)
        double hNextAngleRaw = fmod((startTime + 1) / 120.0, 360.0);
        double mNextAngleRaw = fmod((startTime + 1) / 10.0, 360.0);
        double sNextAngleRaw = fmod((startTime + 1) * 6.0, 360.0);

        double hNextAngle = (hNextAngleRaw == 0.0) ? 360.0 : hNextAngleRaw;
        double mNextAngle = (mNextAngleRaw == 0.0) ? 360.0 : mNextAngleRaw;
        double sNextAngle = (sNextAngleRaw == 0.0) ? 360.0 : sNextAngleRaw;

        if (sCurAngle < hCurAngle && sNextAngle >= hNextAngle) {
            answer++;
        }
        if (sCurAngle < mCurAngle && sNextAngle >= mNextAngle) {
            answer++;
        }
        // 중복 카운팅 제거
        if (sNextAngle == hNextAngle && hNextAngle == mNextAngle) {
            answer--;
        }

        startTime++;
    }

    return answer;
}
