def solution(board, skill):
    R = len(board)
    C = len(board[0])
    dp = [[0] * (C + 2) for _ in range(R + 2)] # 차이 배열
    
    # 쿼리에 대해 차이 배열(dp)에 갱신
    for t, r1, c1, r2 ,c2 ,d in skill:
        if t == 1: d = -d
        r1, c1, r2, c2 = r1 + 1, c1 + 1, r2 + 1, c2 + 1
        dp[r1][c1] += d
        dp[r1][c2 + 1] -= d
        dp[r2 + 1][c1] -= d
        dp[r2 + 1][c2 + 1] += d
    
    for y in range(1, R + 1):
        for x in range(1, C + 1):
            dp[y][x] += (dp[y][x - 1] + dp[y - 1][x] - dp[y - 1][x - 1])
    
    ans = R * C
    for y in range(R):
        for x in range(C):
            ans -= (board[y][x] + dp[y + 1][x + 1] <= 0)
    
    return ans
