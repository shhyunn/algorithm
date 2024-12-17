import sys
input = sys.stdin.readline

N, M = map(int, input().split(" "))
A = []
B = []

for _ in range(N):
    temp = list(map(int, list(input().strip())))
    A.append(temp)

for _ in range(N):
    temp = list(map(int, list(input().strip())))
    B.append(temp)

def convert(x,y):
    for ii in range(x, x+3):
        for jj in range(y, y+3):
            A[ii][jj] = 1 - A[ii][jj]

def solution():
    if A == B:
        return 0
    
    cnt = 0

    for i in range(N-2):
        for j in range(M-2):
            if A[i][j] != B[i][j]:
                convert(i,j)
                cnt += 1
            if A == B:
                return cnt
    
    return -1
            
print(solution())