import sys
from collections import defaultdict
input = sys.stdin.readline

#가장 유명한 사람 -> 2-친구의 수가 가장 많은 사람
N = int(input())
arr = []
dic = defaultdict(set)

for i in range(N):
    temp = list(input().strip())
    for id, v in enumerate(temp):
        if v == "Y":
            dic[i].add(id)

max_cnt = -1

for i in range(N):
    temp = set([])
    current = dic[i]
    temp.update(dic[i])

    for j in range(N):
        if i == j:
            continue
        next = dic[j]
        test = next & current
        if len(test) > 0:
            temp.add(j)
    
    max_cnt = max(max_cnt, len(temp))

print(max_cnt)