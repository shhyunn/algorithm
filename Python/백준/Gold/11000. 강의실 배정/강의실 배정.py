import sys, heapq

input = sys.stdin.readline

N = int(input())
arr = []

for _ in range(N):
    s, t = map(int,input().split())
    arr.append((s,t))


arr.sort()

stack = []
heapq.heappush(stack,arr[0][1])

for i in range(1, N):
    if (arr[i][0] <stack[0]):
        heapq.heappush(stack,arr[i][1])
    else:
        heapq.heappop(stack)
        heapq.heappush(stack, arr[i][1])

print(len(stack))
