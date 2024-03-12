import sys, heapq
input = sys.stdin.readline

N,M,X = map(int, input().split())#n명의 학생이 x번 마을에 모여 파티, m개 도로
#오고 가는데 가장 많은 시간을 소비하는 학생은?
inf = 1e9
#dijkstra algorithm
dic_1 = {key:[] for key in range(1,N+1)}
dic_2 = {key:[] for key in range(1,N+1)}
for _ in range(M): #m개의 단방향 도로
    s,e,t = map(int, input().split()) #시작점과 끝점이 같은 도로는 없음
    dic_1[s].append((t,e)) #x가 시작인 것으로..
    dic_2[e].append((t,s)) #x가 끝인 것으로..

res_1 = [inf for _ in range(N+1)]
res_2 = [inf for _ in range(N+1)]

def go():
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

def back():
    stack = [(0,X)] #x로 도착해야됨!
    res_2[X] = 0
    while stack:
        dist,v = heapq.heappop(stack)
        if res_2[v] < dist:
            continue
        
        for k,n in dic_2[v]:
            if res_2[n] > k + dist:
                res_2[n] = k + dist
                heapq.heappush(stack, (res_2[n],n))

go()
back()

max_val = -1
for i in range(1,N+1):
    max_val = max(max_val, res_1[i]+res_2[i])

print(max_val)