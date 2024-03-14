import sys
input =sys.stdin.readline

N,M = map(int, input().split())
res = []
def bfs(start):
    if len(res) == M:
        print(" ".join(map(str,res)))
        return
    for i in range(start,N+1):
        res.append(i)
        bfs(i+1)
        res.pop()

bfs(1)