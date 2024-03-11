# Floyd-Warshall(플로이드 워셜)

* 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야하는 경우 사용
* 단계마다 거쳐 가는 노드를 기준으로 알고리즘 수행
* 2차원 테이블에 최단 거리 정보를 저장 (DP, 점화식으로 2차원 리스트 갱신)
  -> 점화식
  ![image](https://github.com/shhyunn/algorithm/assets/108120508/98ff7874-581e-4497-b32c-6f5650a7b06a)

1. 초기 그래프를 인접행렬로 나타내기, 가는 길이 없다면 inf로 표현
2. 각 노드를 중간 노드로 설정하여 그 노드를 거쳐가는 경우의 수로 최단거리 갱신

> 시간 복잡도 O(n^3) </br>
>  그래프의 크기가 작아 세제곱 시간 알고리즘을 적용해도 괜찮을 때만 적용 가능

## Code
```python
import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
inf = 1e9
floyd = [[inf for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int, input().split())
    floyd[a][b] = min(floyd[a][b], c)

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i == j:
                continue

            floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])
```
