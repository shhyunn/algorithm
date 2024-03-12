# Dijkstra Algorighm (다익스트라 알고리즘)
* 다이나믹 프로그래밍을 활용한 최단 경로 탐색 알고리즘, 최단거리는 여러개의 최단거리로 이루어져있음
* 하나의 정점에서 다른 모든 정점으로 가는 최단 경로 탐색

## 작동 과정
1. 출발 노드 설정
2. 출발 노드를 기준으로 각 노드의 최소 비용 저장
3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용 갱신

## Code
```python
    stack = [(0,X)] #x에서 되돌아가자
    res_1[X] = 0
    while stack:
        dist,v = heapq.heappop(stack)
        if res_1[v] < dist:
            continue

        for k,n in dic_1[v]:
            if res_1[n] > k + dist:
                res_1[n] = k + dist
                heapq.heappush(stack, (res_1[n],n))
```
* 우선순위 큐를 사용하여 현재 거리가 가장 짧은 노드를 가져온다.
* 현재 저장된 거리가 더 짧다면 continue
* 노드와 연결된 이웃 노드들을 살펴보며 더 거리가 짧게 갱신된다면 큐에 저장한다.
