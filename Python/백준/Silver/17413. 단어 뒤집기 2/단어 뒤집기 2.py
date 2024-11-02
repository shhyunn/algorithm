import sys
input = sys.stdin.readline

#문자열 입력받기
strr = input().strip()

res = ''
stack = []
pss = False

for s in strr:
    if s == ' ':
        if pss:
            stack.append(s)
            continue

        if stack:
            res += "".join(stack[::-1])
            stack = []
        res += s

    elif s == '<':
        pss = True
        if stack:
            res += "".join(stack[::-1])
            stack = []
        stack.append(s)

    elif s == '>':
        pss = False
        stack.append(s)
        res += "".join(stack)
        stack = []
    else:
        stack.append(s)

if stack:
    res += "".join(stack[::-1])

print(res)