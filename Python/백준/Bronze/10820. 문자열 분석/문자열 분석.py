import sys

strLst = sys.stdin.read().splitlines()

res = []

for s in strLst:
    temp = [0 for _ in range(4)]
    for c in s:
        if c.islower():
            temp[0] += 1  # 소문자 개수
        elif c.isupper():
            temp[1] += 1  # 대문자 개수
        elif c.isdigit():
            temp[2] += 1  # 숫자 개수
        else:
            temp[3] += 1  # 기타 문자 개수

    res.append(temp)

for r in res:
    print(*r)