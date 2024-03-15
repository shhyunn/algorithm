import sys
input = sys.stdin.readline
N = int(input())
arr = []
for _ in range(N):
    temp = list(map(int, input().split()))
    arr.append(temp)
    #1,1괴 1,2는 항상 빈칸 (파이프 현재 위치)
    #n,n으로 이동시키는 방법의 개수

res = 0
def recur(r,c,d):#r,c
    global res
    if r == N-1 and c == N-1:
        res += 1
        return
    
    if d != 2: #오른쪽
        if c+1 < N and arr[r][c+1] == 0:
            recur(r,c+1,0)
    
    if d != 0: #아래쪽
        if r+1 < N and arr[r+1][c] == 0:
            recur(r+1,c,2)
    
    if r+1 < N and c+1 < N and arr[r+1][c] == 0 and arr[r][c+1] == 0 and arr[r+1][c+1] == 0:
        recur(r+1,c+1,1)

recur(0,1,0)
print(res)