def solution(m, n, puddles):
    # Puddles를 집합으로 변환
    puddle_set = {(a-1, b-1) for a, b in puddles}
    
    # 1차원 DP 배열 초기화
    dp = [0] * m
    dp[0] = 1  # 시작점
    
    for i in range(n):  # 행
        for j in range(m):  # 열
            if (j, i) in puddle_set:  # 물 웅덩이일 경우
                dp[j] = 0
            elif j > 0:  # 물 웅덩이가 아닌 경우
                dp[j] += dp[j-1]
    
    return dp[m-1] % 1000000007  # 최종 결과 반환