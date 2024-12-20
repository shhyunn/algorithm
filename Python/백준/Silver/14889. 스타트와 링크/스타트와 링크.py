import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().strip().split(" "))) for _ in range(N)]

s , l = [], []
diff = 1e9

def dfs(i):
    global s, l, diff

    if len(s) == N//2 and len(l) == N//2:
        s_comb = list(combinations(s, 2))
        l_comb = list(combinations(l, 2))
        s_sum = 0
        l_sum = 0

        for sc in s_comb:
            s_sum += arr[sc[0]][sc[1]]
            s_sum += arr[sc[1]][sc[0]]

        for lc in l_comb:
            l_sum += arr[lc[0]][lc[1]]
            l_sum += arr[lc[1]][lc[0]]
        
        diff = min(diff, abs(s_sum - l_sum))

    if len(s) < N//2:
        s.append(i)
        dfs(i+1)
        s.remove(i)

    if len(l) < N//2:
        l.append(i)
        dfs(i+1)
        l.remove(i)

dfs(0)
print(diff)