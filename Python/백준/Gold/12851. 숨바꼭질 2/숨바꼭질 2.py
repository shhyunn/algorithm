from collections import deque
import sys
input = sys.stdin.readline

N, K = map(int , input().split())
#동생을 찾을 수 있는 가장 빠른 시간
max_value = 200000
visited = [0] * (max_value + 1)

ans_sec = 100001
stack =deque([N])
res = 0

while stack:
    curr = stack.popleft()
    if visited[curr] > ans_sec:
        break

    if curr == K:
        if ans_sec == 100001:
            ans_sec = visited[curr]

        if visited[curr] == ans_sec:
            res += 1
        continue

    samples = [curr+1, curr-1, curr * 2]

    for s in samples:
        if 0 <= s <= max_value and (visited[s] == 0 or visited[s] == visited[curr] + 1):
            visited[s] = visited[curr] + 1
            stack.append(s)


print(ans_sec)
print(res)
