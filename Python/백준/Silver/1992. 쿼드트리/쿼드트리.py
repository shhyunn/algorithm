import sys
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(input().strip()))

def dfs(i,j,n, cnt):
    if n == 1:
        return arr[i][j]
    
    temp = ""
    
    temp += dfs(i,j,n//2, cnt+1)
    temp += dfs(i, j+n//2, n//2, cnt+1)
    temp += dfs(i+n//2,j,n//2, cnt+1)
    temp += dfs(i+n//2, j+n//2, n//2,cnt+1)

    if temp == "1111":
        return "1"
    elif temp == "0000":
        return "0"
    else:
        return "("+temp+")"



res = dfs(0,0,N, 0)
print(res)