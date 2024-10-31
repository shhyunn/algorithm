import sys
input = sys.stdin.readline

N, K = map(int, input().split(" "))
arr = [i for i in range(1, N+1)]

i = 0
cnt = 0
res = []
while arr:
    cnt += 1
    if cnt == K:
        res.append(arr[i])
        arr.remove(arr[i])
        cnt = 0
        if i == len(arr):
            i = 0
        continue

    else:
        if i+1 == len(arr):
             i = 0
        else:
            i += 1      
print("<"+", ".join(map(str,res))+">")