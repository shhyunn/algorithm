import sys, heapq
input = sys.stdin.readline
N,E = map(int,input().split())
graph = {key:[] for key in range(1,N+1)}
for _ in range(E):
    a,b,c = map(int, input().split()) #양방향 길이
    graph[a].append((b,c))
    graph[b].append((a,c))

v1,v2 = map(int, input().split()) #두 정점 사이에 간선이 최대 1개
#두 개의 정점을 지나는 최단 경로의 길이 출력
#한 번 이동했던 간선도 다시 이동 가능!, 최단 경로로 이동해야 함
#1번 정점에서 N번 정점으로 최단 거리로 이동
#1번v1번v2번N번
#1번v2번v1번N번

lst1 = [1,v1,v2,N]
lst2 = [1,v2,v1,N]

def dk(start,end): #1번에서 v1까지
    if start == end:
        return 0
    #다익스트라는 visited 여부가 필요 없음!!
    distance = [1e9 for _ in range(N)]
    distance[0] = 0
    stack = [(0,start)]

    while stack:
        d,v = heapq.heappop(stack) #0,2
        if distance[v-1] < d:
            continue
        
        for k in graph[v]:
            next,dist = k[0], k[1]
            if distance[next-1] > d + dist:
                distance[next-1] = d + dist
                heapq.heappush(stack, (distance[next-1],next))
    return distance[end-1]

res1, flag1 = 0, 1
for i in range(3):
    temp = dk(lst1[i],lst1[i+1])
    if temp == 1e9:
        flag1 = 0
        break
    res1 += temp

res2, flag2 = 0, 1
for i in range(3):
    temp = dk(lst2[i],lst2[i+1])
    if temp == 1e9:
        flag2 = 0
        break
    res2 += temp

if flag1 == 0 and flag2 == 0:
    print(-1)

else:
    res = 1e9
    if flag1 == 1:
        res = min(res1,res)
    if flag2 == 1:
        res = min(res2, res)
    
    print(res)