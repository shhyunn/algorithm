import sys

input = sys.stdin.readline

N = int(input())
data = []
for _ in range(N):
	start, end = map(int, input().split())
	data.append((start, end))

data.sort()
last = 0
cnt = 0

for i in range(N):
	s, e = data[i]
	if last <= s: #스타트 시점이 last 이상이라면
		last = e
		cnt += 1

	else: #스타트 시점이 last 미만이라면
		if e < last:
			last = e # 교체

print(cnt)