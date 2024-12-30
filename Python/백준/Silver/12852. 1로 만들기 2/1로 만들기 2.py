import sys
input = sys.stdin.readline

N = int(input())

visited = [False for _ in range(N)]
dp = [1e9] * (N+1)
strr = [""] * (N+1)

dp[1] = 0
for i in range(1,N+1):
    if 1 <= i*3 <= N:
        if dp[i] + 1 < dp[i*3]:
            strr[i*3] = strr[i] + str(i)+" "

        dp[i*3] = min(dp[i] + 1, dp[i*3])
        
    if 1 <= i*2 <= N:
        if dp[i] + 1 < dp[i*2]:
            strr[i*2] = strr[i] + str(i)+" "
        dp[i*2] = min(dp[i] + 1, dp[i*2])
        

    if 1 <= i+1 <= N:
        if dp[i] + 1 < dp[i+1]:
            strr[i+1] = strr[i] + str(i)+" "
        dp[i+1] = min(dp[i]+ 1, dp[i+1])

print(dp[N])
res = strr[N].split(" ")[::-1]
print(str(N), end="")
print(*res)