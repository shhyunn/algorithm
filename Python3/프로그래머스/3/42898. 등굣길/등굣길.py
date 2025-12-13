#dp로 풀기



def solution(m, n, puddles):
    
    board = [[0 for _ in range(n)] for _ in range(m)]
    dp = [[0 for _ in range(n)] for _ in range(m)]
    
    for px, py in puddles:
        board[px-1][py-1] = -1
        
    
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                dp[i][j] = 1
                continue
            
            if board[i][j] == -1:
                dp[i][j] = 0
                continue
                
            if i > 0:
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007
            
            if j > 0:
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007
                
    return dp[m-1][n-1]