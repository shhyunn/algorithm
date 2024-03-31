import sys
input = sys.stdin.readline
strr = input().strip()
bomb = input().strip()

last = []
stack = []
i = 0
for ch in strr:
    stack.append(ch)

    if ch == bomb[i]: #bomb[i] 이랑 같다면
        i += 1

    else: #bomb[i]랑 다르다면
        if ch == bomb[0]:
            last.append(i)
            i = 1
        else:
            last.append(0)
            i = 0
    
    if i == len(bomb): #bomb!
        for _ in range(len(bomb)):
            stack.pop()
        if last and last[-1] != 0:
            i = last.pop()
        else:
            i = 0
if stack:
    print("".join(stack))
else:
    print("FRULA")