import sys,copy
from itertools import combinations
input = sys.stdin.readline
#빈칸, 치킨집, 집, 집과 가장 가까운 치킨집 거리, 각각의 집은 치킨 거리를 가지고 있음
#도시의 치킨 거리가 가장 작게 될까?
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
