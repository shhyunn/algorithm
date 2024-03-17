# Depth-First Search Algorithm
* 트리나 그래프를 탐색하는 기법 중 하나로, 시작 노드에서 자식의 노드들을 순서대로 탐색하면서 깊이를 우선으로 탐색하는 알고리즘
* 반복문 혹은 재귀문을 이용해 구현

## 동작 과정
* 현재 노드를 방문으로 표시
* 방문한 표시가 되어 있지 않은 각각의 인접한 정점을 탐색
* 더 이상 방문하지 않은 정점이 없으면 이전 정점으로 역추적
* 모든 정점을 방문할 때까지 프로세스를 반복

## 장점 및 단점
### 장점
* DFS는 현재 순회 중인 정점만 저장하는 스택 데이터 구조를 사용하기 때문에 BFS에 비해 메모리 공간을 덜 차지함
* DFS는 목표가 특정 정점 또는 모든 정점에 최대한 빨리 도달하는 것일 때 유용함
* DFS를 사용하여 그래프 순환 감지 가능

### 단점
* 순환 그래프의 경우 DFS가 무한 루프에 빠질 수 있음
* DFS는 두 정점 사이의 최단 경로를 찾으려는 경우 사용하기에 가장 좋은 알고리즘은 아님

## 예시 문제 코드 (백준 1043번)
```python3
import sys
input = sys.stdin.readline

#이야기의 진실을 아는 사람, 모든 파티에 참가해야 함, 과장된 이야기를 할 수 있는 파티 개수의 최댓값
N,M = map(int, input().split())
plist = list(map(int, input().split())) #진실한 이야기를 알고있는 사람
pnum = plist[0] #사람 수
party = [] #party 리스트
person = {key:[] for key in range(1,N+1)}
party_num = [0 for _ in range(M)]
visited = [False for _ in range(N+1)]

for i in range(M):
    temp = list(map(int, input().split()))
    party_num[i] = temp[0]
    party.append(temp[1:]) #해당 party에 대해 참가한 사람 리스트
    for k in temp[1:]: #사람 리스트
         person[k].append(i)

def dfs(k): #dfs할 사람
        for p in person[k]: #그 person이 참가한 party
            party_num[p] -= 1
            for n in party[p]: #party에 참가한 리스트
                # print(p,n)
                if not visited[n]:
                    visited[n] = True
                    dfs(n)

for i in range(1,pnum+1):
    visited[plist[i]] = True
    dfs(plist[i]) #3으로 시작

cnt = 0
for r in party_num:
     if r > 0:
          cnt += 1

print(cnt)
```
* 진실을 알고 있는 사람에게는 거짓말이 안통하니, 거짓말을 할 수 있는 파티 그룹 수를 구하는 문제
* bfs로 구현하려다 어려움을 느껴 dfs 이용하여 문제 해결
* 아직까지도 dfs는 구현하는 데 어색함을 느낀다.. 많이 연습해봐야 할 것 같다.
* dfs는 재귀 혹은 스택으로 구현할 수 있는데 재귀가 훨씬 직관적이고 간편하다
* 진실을 아는 사람을 백트래킹이 가능한 스택으로 따로 빼서 재귀호출이 가능하도록 하는게 이 문제의 핵심이다.
