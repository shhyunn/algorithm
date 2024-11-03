import sys
input = sys.stdin.readline

N = int(input().strip())
arr = list(map(int, input().split(" ")))

#오큰수: 오른쪽에 있으면서 나보다 더 크면서 가장 왼쪽에 있는 , 없다면 -1

maxArr = [-1 for _ in range(N)]
stack = []

for i, n in enumerate(arr):
    if i == 0:
        stack.append((i,n))
        continue

    if stack and stack[-1][1] > n:
        stack.append((i,n))
    else:
        while stack and stack[-1][1] < n:
            ti, tn = stack.pop()
            maxArr[ti] = n
        stack.append((i,n))

print(" ".join(map(str,maxArr)))
