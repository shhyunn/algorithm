import sys
input = sys.stdin.readline

N = int(input().strip())
lst = list(map(int, input().strip().split(" "))) 
num = int(input().strip())

start = 0
end = num
max_num = 0
while start <= end:
    sums = []
    mid = (start + end) // 2
    for s in lst:
        t = min(mid, s)
        sums.append(t)
    
    if sum(sums) <= num:
        max_num = max(max_num, max(sums))
        start = mid + 1
    else:
        end = mid - 1

print(max_num)