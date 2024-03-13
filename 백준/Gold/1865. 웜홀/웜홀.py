import sys
input = sys.stdin.readline
tc = int(input())

def bf():
    for i in range(N):
        for j in range(len(edges)):
            cur, next, cost = edges[j]

            if distance[next] > distance[cur] + cost:
                distance[next] = distance[cur] + cost
                if i == N-1:
                    return True
    return False

for _ in range(tc):
    N,M,W = map(int, input().split())
    edges = []
    for _ in range(M):
        S,E,T = map(int, input().split())
        edges.append((S,E,T))
        edges.append((E,S,T))

    for _ in range(W):
        S,E,T = map(int, input().split())
        edges.append((S,E,-T))
    
    inf = 1e9
    distance = [inf for _ in range(N+1)]

    if bf():
        print("YES")
    else:
        print("NO")