import sys
input = sys.stdin.readline

N = int(input().strip())
arr = list(map(int, input().strip().split(" ")))

dict = {}
for n in arr:
    if n not in dict.keys():
        dict[n] = 1
    else:
        dict[n] += 1

res = [-1 for _ in range(N)]

stack = []

for i, n in enumerate(arr):
    if i == 0:
        stack.append((i,dict[n]))
        continue

    if stack[-1][1] < dict[n]:
        #현재 추가하려는 n의 횟수가 stack의 마지막 수의 횟수보다 클경우
        while stack and stack[-1][1] < dict[n]:
            ti, tn = stack.pop()
            res[ti] = n

    stack.append((i,dict[n]))

print(*res)
