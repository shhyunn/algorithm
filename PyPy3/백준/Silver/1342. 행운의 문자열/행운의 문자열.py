import sys
from collections import Counter

input = sys.stdin.readline

strr = input().strip()

ss = Counter(strr)

def backtracking(prev, l):
    answer = 0
    if l == len(strr):
        return 1
    
    for k in ss.keys():
        if prev == k or ss[k] == 0:
            continue
        ss[k] -= 1
        answer += backtracking(k, l+1)
        ss[k] += 1
    return answer

answer = backtracking("", 0)
print(answer)