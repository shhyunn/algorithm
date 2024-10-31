import sys
input = sys.stdin.readline
N = int(input())
M = int(input())
S = input().strip()

pat = "I"
pat += "OI"*N
ll = len(S)
i = 0
status = 1
cnt = 0
res = []
pat_ll = len(pat)

while i < ll:
    if status == 1: #i가 나와야됨
        if S[i] == "I":
            cnt += 1
            status = 0
        else: #O가 나옴, 전에 O
            if cnt >= pat_ll:
                res.append(cnt)
            cnt = 0

    else: #O가 나와야됨
        if S[i] == "O":
            cnt += 1
            status = 1
        else:
            if cnt >= pat_ll:
                res.append(cnt)
            cnt = 1
            status = 0
    i += 1
if cnt >= pat_ll:
    res.append(cnt)
    
total = 0
for cnt in res:
    total+= (cnt-pat_ll)//2+1
print(total)