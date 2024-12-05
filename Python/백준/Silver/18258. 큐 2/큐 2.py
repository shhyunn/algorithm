import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
stack = deque([])
for _ in range(N):
    strr = input().strip()

    if strr.startswith("push"):
        _, n = strr.split(" ")
        stack.append(int(n))
    
    elif strr.startswith("pop"):
        if stack:
            n = stack.popleft()
            print(n)
        else:
            print(-1)
    
    elif strr.startswith("size"):
        print(len(stack))
    
    elif strr.startswith("empty"):
        if stack:
            print(0)
        else:
            print(1)
    
    elif strr.startswith("front"):
        if stack:
            print(stack[0])
        else:
            print(-1)
    else:
        if stack:
            print(stack[-1])
        else:
            print(-1)