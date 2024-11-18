def solution(triangle):
    #대각선으로 한칸 오른쪽 / 왼쪽으로 한칸 오른쪽
    answer = 0
    h = len(triangle)
    dp = [[0 for _ in range(h)] for _ in range(h)]
    dp[0][0] = triangle[0][0]
    
    for i in range(1, h):
        for j in range(i+1):
            if j < 1:
                dp[i][j] = dp[i-1][j] + triangle[i][j]
            elif j == i:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
                
    answer = max(dp[h-1])
            
    return answer