import sys
input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().strip().split(" ")))
res = [0] * len(arr)

for i, v in enumerate(arr):
    cnt = 0
    for ri, r in enumerate(res):
        if r == 0:
            if v == cnt:
                res[ri] = i + 1
                break
            cnt += 1
print(*res)