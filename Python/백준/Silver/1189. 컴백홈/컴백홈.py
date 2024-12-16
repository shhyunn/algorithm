import sys, copy
from collections import deque

input = sys.stdin.readline

R, C, K = map(int, input().strip().split(" "))
arr = []
for _ in range(R):
    temp = list(input().strip())
    arr.append(temp)

stack = deque([((R-1, 0), set([(R-1, 0)]))])
move = [(-1,0), (1,0), (0,1), (0,-1)]

cnt = 0
while stack:
    dir, set_arr = stack.popleft()
    lens = len(set_arr)
    if lens == K and dir == (0, C-1):
        cnt += 1
        continue

    if lens > K:
        continue

    for cx, cy in move:
        dx = dir[0] + cx
        dy = dir[1] + cy

        if 0 <= dx < R and 0 <= dy < C and arr[dx][dy] != "T" and (dx, dy) not in set_arr:
            curr = copy.deepcopy(set_arr)
            curr.add((dx, dy))
            stack.append(((dx, dy), curr))

print(cnt)