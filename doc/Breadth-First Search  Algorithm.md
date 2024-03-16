# Breadth-First Search Algorithm (너비 우선 탐색)
* 그래프에서 시작 노드에 인접한 노드부터 탐색하는 알고리즘
* 그래프에서 모든 간선의 비용이 동일한 조건에서 최단 거리를 구하는 문제를 효과적으로 해결할 수 있는 알고리즘
* 선입선출 방식의 큐 자료구조를 사용함

## 작동 과정
1. 탐색 시작 노드 정보를 큐에 삽입하고 방문 처리
2. 큐에서 노드를 꺼내 방문하지 않은 인접 노드 정보를 모두 큐에 삽입하고 방문 처리
3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복

## 예시 문제 코드
```python3
import sys
from collections import deque
input = sys.stdin.readline

N,M = map(int, input().split())
arr = []
visited = [[[False,False] for _ in range(M)] for _ in range(N)]
for _ in range(N):
    temp = input().strip()
    arr.append(temp)

stack = deque([(1,(0,0),0)]) #거리,좌표, 벽 부수기 유무
visited[0][0][0] = True
move_x = [-1,1,0,0]
move_y =[0,0,-1,1]
res = 1e9
while stack:
    d, (x,y), flag =stack.popleft()
    if x == N-1 and y == M-1:
        res = min(res, d)
        continue

    for i in range(4):
        cx = x + move_x[i]
        cy = y + move_y[i]

        if 0 <= cx < N and 0 <= cy < M:
            if flag == 1 and not visited[cx][cy][1] and arr[cx][cy] == '0': #벽이 아닌데 벽을 이미 부쉈어, 근데 방문을 안했어
                visited[cx][cy][1] = True
                stack.append((d+1,(cx,cy),flag))
            
            elif flag == 0 and not visited[cx][cy][0] and arr[cx][cy] == '0': #벽을 안부쉈는데 아직 안갔어, 벽이 없어
                visited[cx][cy][0] = True
                stack.append((d+1,(cx,cy),flag))
            
            elif flag == 0 and not visited[cx][cy][1] and arr[cx][cy] == '1': #벽을 안부쉈고 이제 부술거야
                visited[cx][cy][1] = True
                stack.append((d+1, (cx,cy),1))

            # if flag == 1 and arr[cx][cy] == '1':
            #     continue
            # else:
            #     if not visited[cx][cy][1] and arr[cx][cy] == '1' and flag == 1: #벽을 부쉈는데, 1이 나타남
                   
            #         #heapq.heappush(stack, (d+1,(cx,cy),1))
            #     elif arr[cx][cy] == '0':
            #         if not visited[cx][cy][0] and flag == 0:
            #             visited[cx][cy][0] = True
            #             stack.append((d+1,(cx,cy),flag))

            #         elif not visited[cx][cy][1] and flag == 1:
            #             visited[cx][cy][1] = True
            #             stack.append((d+1,(cx,cy),flag))
            #             #heapq.heappush(stack, (d+1,(cx,cy),flag))

if res == 1e9:
    print(-1)
else:
    print(res)
```
* 벽 아니면 빈칸으로 되어있는 맵에서 벽은 최대 한번까지 통과할 수 있는 최단 경로를 구하는 문제
* dp로 접근했다가 아닌 것 같아서 bfs로 선회
* 조건 설정에서 어려움을 겪었다. 벽을 뚫었을 때 flag과 visited 여부를 설정을 모호하게 작성했음
  -> 조건 설정을 명확하게 하도록 주의하자
