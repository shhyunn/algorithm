s = input()
r = input()

ls = len(s)
lr = len(r)

dp = [[0 for _ in range(lr+1)] for _ in range(ls+1)]

for i in range(1, ls+1):
    for j in range(1, lr+1):
        if s[i-1] == r[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

i = ls 
j = lr

res = ""
while i > 0 and j > 0:
    if dp[i-1][j] == dp[i][j]:
        i -= 1
    elif dp[i][j-1] == dp[i][j]:
        j -= 1
    else:
        res += s[i-1]
        i -= 1
        j -= 1

print(len(res))
if len(res) > 0:
    print(res[::-1])
