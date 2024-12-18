import sys, heapq
input = sys.stdin.readline

N, D = map(int, input().strip().split(" "))

distance = [i for i in range(D+1)]

arr = []

for _ in range(N):
    s, d, l = map(int, input().strip().split(" "))
    if d - s > l:
        heapq.heappush(arr, (s,d,l))
        arr.append((s,d,l))

while arr:
    s, d, l = heapq.heappop(arr)

    for i in range(1, D+1):
        if i == d:
            distance[i] = min(distance[i], distance[s] + l)
        else:
            distance[i] = min(distance[i], distance[i-1] + 1)

print(distance[D])