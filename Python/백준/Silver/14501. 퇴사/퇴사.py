import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    T, P = map(int, input().split())
    arr.append((T, P))

res = 0

def dfs(i, n):
    global res
    if i >= N:
        return

    t, p = arr[i]
    if i+t <= N:
        dfs(i+t, n+p)
        res = max(res,n+p)
    dfs(i+1, n) 


dfs(0,0)
print(res)