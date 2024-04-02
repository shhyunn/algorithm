import sys
from collections import deque
#bfs + 이진탐색
#몇개의 섬 사이에는 다리가 설치되어 있음
#한번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값
#서로 같은 두 섬 사이에 여러 개의 다리가 있을 수 있음 & 다리는 양방향
input = sys.stdin.readline
N,M = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

for i in range(1,N+1):
    graph[i].sort(reverse=True)

def bfs(mid):
    visited[start] = 1
    q = deque()
    q.append(start)

    while q:
        now = q.popleft()
        if now == end:
            return True
        for nx, nc in graph[now]:
            if visited[nx] == 0 and mid <= nc:
                q.append(nx)
                visited[nx] = 1
    return False

start, end = map(int, input().split())
low, high = 1, 1000000000
while low <= high:
    visited = [0 for _ in range(N+1)]
    mid = (low + high) // 2
    if bfs(mid):
        low = mid + 1
    else:
        high = mid - 1
print(high)