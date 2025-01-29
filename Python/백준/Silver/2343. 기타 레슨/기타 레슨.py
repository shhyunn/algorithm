import sys
input = sys.stdin.readline

N, M = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

start = max(arr)
end = sum(arr)

res = end

while start <= end:
    mid = (start + end) // 2 #블루레이 크기
    temp = 0
    cnt = 1
    for a in arr:
        if temp + a <= mid:
            temp += a
        else:
            temp = a
            cnt += 1
    if cnt > M: #블루레이 개수가 더 많아짐.. 커져야함..
        
        start = mid+1
    else: #블루레이 개수가 더 적음.. 줄여야함..
        end = mid-1
        res = min(res, mid)

print(res)