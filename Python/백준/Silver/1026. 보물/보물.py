import sys
input = sys.stdin.readline

N = map(int, input().strip())
A = list(map(int, input().strip().split()))
B = list(map(int, input().strip().split()))

A.sort()
B.sort(reverse=True)

sums = 0
for a,b in zip(A,B):
    sums += a*b

print(sums)
