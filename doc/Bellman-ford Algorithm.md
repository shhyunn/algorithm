# Bellman-ford (벨만-포드) 알고리즘
* 그래프에서 음수 가중치를 가진 간선이 있을 때 최단거리를 구하는 알고리즘
* 매번 모든 간선을 확인하기 때문에 다익스트라에 비해 느림

  ![image](https://github.com/shhyunn/algorithm/assets/108120508/afbaa137-96d2-469f-a5f3-bc2f78b2b03e)
## 단계
1. Edge 리스트로 그래프를 구현하고 최단경로 배열 초기화하기
2. 모든 Edge를 확인해 최단경로 배열 업데이트하기
3. 음수 사이클 확인, 한번 더 반복하며 모든 노드 탐색 후, 업데이트되는 노드가 있다면 음수사이클 존재

## Code
```python3
def bf():
    for i in range(N):
        for j in range(len(edges)):
            curr,next,cost = edges[j]
            if distance[next] > distance[curr] + cost:
                distance[next] = distance[curr] + cost
                if i == N-1:
                    return True
    return False
```
* N개의 노드만큼, 간선의 개수만큼 반복 -> 시간복잡도: O(NE)
* 현재 노드까지의 거리 + cost 가 다음 노드의 거리보다 작다면 업데이트
* 이때 업데이트 하는 횟수가 모든 노드에 대한 간선 횟수를 초과할 경우, 음수 사이클 존재, True 리턴 
