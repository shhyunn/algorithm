import sys, heapq
input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N = int(input())
    lst = []
    for _ in range(N):
        t1, t2 = map(int, input().strip().split(" "))
        heapq.heappush(lst, (t1,t2))
    
    cnt = 0
    min_value = N
    while lst:
        a, b = heapq.heappop(lst)
        
        if min_value == N:
            cnt += 1
            min_value = b
            continue
        
        
        if min_value < b:
            continue
        
        cnt += 1
        min_value = b
    
    print(cnt)