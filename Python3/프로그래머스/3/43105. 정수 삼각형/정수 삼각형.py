def solution(triangle):
    #경로에서 거쳐간 숫자의 합이 가장 큰 경우
    l = len(triangle[-1])
    dp = [[0 for _ in range(l)] for _ in range(l)]
    
    for i in range(l):
        for j in range(i+1):
            if i == 0:
                dp[i][j] = triangle[i][j]
                continue
            
            if j == 0:
                dp[i][j] = dp[i-1][j] + triangle[i][j]
                continue
            
            if j == i:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                continue
            
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
            
    return max(dp[l-1])
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     #대각선으로 한칸 오른쪽 / 왼쪽으로 한칸 오른쪽
#     answer = 0
#     h = len(triangle)
#     dp = [[0 for _ in range(h)] for _ in range(h)]
#     dp[0][0] = triangle[0][0]
    
#     for i in range(1, h):
#         for j in range(i+1):
#             if j < 1:
#                 dp[i][j] = dp[i-1][j] + triangle[i][j]
#             elif j == i:
#                 dp[i][j] = dp[i-1][j-1] + triangle[i][j]
#             else:
#                 dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
                
#     answer = max(dp[h-1])
            
#     return answer