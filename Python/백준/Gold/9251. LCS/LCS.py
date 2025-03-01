import sys
input = sys.stdin.readline

str1 = input().strip()
str2 = input().strip()

il = len(str1)
jl = len(str2)

dp = [[0 for _ in range(jl+1)] for _ in range(il+1)]

for i in range(1, il+1):
    for j in range(1,jl+1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1

        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[il][jl])
