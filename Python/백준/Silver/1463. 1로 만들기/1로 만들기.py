import sys
input = sys.stdin.readline

n = int(input())

dp = [-1] * (n+1)
dp[0] = 0
dp[1] = 0

def dps(n):
    if dp[n] != -1:
        return dp[n]
    
    if n % 6 == 0:
        dp[n] = min(dps(n//3), dps(n//2)) + 1

    elif n % 3 == 0:
        dp[n] = min(dps(n//3), dps(n-1)) + 1

    elif n % 2 == 0:
        dp[n] = min(dps(n//2), dps(n-1)) + 1

    else:
        dp[n] = dps(n-1) + 1
    return dp[n]

print(dps(n))