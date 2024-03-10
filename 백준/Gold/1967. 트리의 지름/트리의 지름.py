import sys
from collections import deque
# sys.stdin = open("C:\\Users\\LG\\proj\\comit\\sohyun\\input.txt","r")
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n = int(input())
dic = {key:[] for key in range(1,n+1)}
for _ in range(n-1):
    p,c,w = map(int, input().split())
    dic[c].append((p,w))
    dic[p].append((c,w))

def dfs(x,d):
    global max_val,id
    if d > max_val:
        max_val = d
        id = x
    for v,t in dic[x]:
        if not visited[v-1]:
            visited[v-1] = True
            dfs(v,d+t)
            visited[v-1] = False

visited = [False for _ in range(n)]
visited[0] = True
max_val = -1
id = -1
dfs(1,0)

visited = [False for _ in range(n)]
visited[id-1] = True
max_val = -1
dfs(id,0)
print(max_val)
