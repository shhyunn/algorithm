import sys
input = sys.stdin.readline

N = int(input())
#개발자 2명 사이에 존재하는 다른 개발자 수와 최소 개발자 능력치
#능력치 최대값!
lst = list(map(int, input().split()))

start, end = 0, len(lst)-1
res = 0
while start <= end:
    x = min(lst[start], lst[end])
    res = max(x*(end-start-1),res)
    if lst[start] == x:
        start += 1
    else:
        end -= 1

print(res)