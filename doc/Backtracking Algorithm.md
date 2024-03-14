# Backtracking(백트래킹)
* 해를 찾는 도중 해가 아니어서 막히면, 되돌아가서 다시 해를 찾아가는 기법
* 지금의 경로가 해가 될 것 같지 않으면 그 경로를 더이상 가지 않고 되돌아감(가지치기)
* DFS 등으로 모든 경우의 수를 탐색하는 과정에서, 조건문 등을 걸어 답이 절대로 될 수 없는 상황을 정의하고, 그러한 상황일 경우에는 탐색을 중지시킨 뒤 그 이전으로 돌아가서 다시 다른 경우를 탐색하게끔 구현

## 예시 문제 코드(백준 15686번)
```python3
# 조건
# 위에서부터 r행, c열 // 단 r과 c는 1부터
# 치킨거리는 집을 기준으로 정해지고 가장 가까운 치킨집과의 거리
# 도시의 치킨 거리는 모든 치킨거리의 합 -> 구해야할 것
# 두 칸 사이의 거리는 |r1-r2|+|c1-c2|
def close(a,b): # 요구사항인 M개 만큼 치킨집을 폐업해보자
    global distance_min
    if a > len(chicken):
        return
    if b == M:
        distance_all = 0
        for r, c in house:
            distance = float('inf')
            for i in val:
                rr, cc = chicken[i]
                distance = min(distance, abs(rr-r)+abs(cc-c))
            distance_all += distance
        distance_min = min(distance_min, distance_all)
        return

    val.append(a)
    close(a+1, b+1)
    val.pop()
    close(a+1,b)
출처: https://edder773.tistory.com/42 [개발하는 차리의 공부 일기:티스토리]
```
-> a가 chicken의 수보다 커질 경우 return하며 부모 노드로 돌아감(백트래킹)
-> 어떤 치킨집을 고려할지를 조합 알고리즘을 사용하였는데, 이때 append 메서도와 pop 메서드로 백트래킹
-> 본인 경우, 비슷하게 백트래킹 방법을 사용하였으나, b가 M의 개수와 동일할 경우에만 거리를 업데이트 하는 것이 아닌 모든 경우에서 업데이트했기에 시간초과 발생
-> a+1은 동일하게, 또 val 리스트에 b+1과 b의 경우를 모두 고려하는데 이는 2C1과 2C2같은 조합 경우의 수에서 a가 왼쪽의 수, b가 오른쪽의 수를 나타냄

## python library itertools - combinations
* combinations 툴을 사용하면 보다 더 쉽게 조합 경우의 수를 구할 수 있음
* combinations_with_replacement는 중복을 포함한 조합 경우의 수 찾기 가능
  ```python3
  N,M = map(int, input().split())
  chicken = []
  visited = [[0 for _ in range(N)] for _ in range(N)]
  home = []
  
  for k in range(N):
      #집의 개수는 2n개를 넘지 않음
      #치킨집의 개수는 M <= x <= 13
      #최대 M개 골랐을 때, 도시의 치킨거리의 최솟값
      temp = list(map(int, input().split()))
      for id,n in enumerate(temp):
          if n == 1:
              home.append((k,id))
          elif n == 2:
              chicken.append((k,id))
  
  coms = combinations(range(len(chicken)), M) #최대 M개
  res = 1e9
  for cc in coms:
      dist = [1e9 for _ in range(len(home))]
      for k in cc:
          c1, c2 = chicken[k][0], chicken[k][1]
          for i,hh in enumerate(home):
              h1, h2 = hh[0], hh[1]
              dist[i] = min(dist[i], abs(c1-h1)+abs(c2-h2))
          if res > sum(dist):
              res = sum(dist)
  
  print(res)
  ```

## 주의할 점
* bfs, dfs, dp, 브루트포스, backtracking... 많은 알고리즘에 대한 문제 풀이을 해보자
  -> 코드 로직을 짜는 데에 너무 많은 시간을 소모..
* bfs, dfs, dp로 안될 것 같은 경우에는 backtracking 이용! 조합을 짜면 어떨지 생각해보자
* 그 조합이 어떠한 경우에 업데이트/삭제가 필요한지를 분명히 하자 <br/>
  -> 이번에도 치킨집은 최대 M개였고, 그 M개를 모두 뽑아 그 중에서 최단거리를 구하는 로직이었다. <br/>
  -> 치킨집이 1개, 2개,,, 일때 모두 거리를 업데이트하는 건 비효율적이고, 시간초과가 발생한다. <br/>
  -> 혼동했던 점 : 최대 M개이기 때문에, 그 M개를 모두 사용하지 않아도 되기 때문에 일일히 거리 업데이트를 해줬었다. <br/>
  -> 최대 M개를 설정한 다음, 거리를 구하자 (조합 사용) -> 문제에 다 명시되어 있다.
