import sys
input = sys.stdin.readline

strr = input().strip()
stack = []
result = 0
prev = ''

for s in strr:
    if s == '(':
        stack.append(s)
        prev = s
    elif s == ')':
        if prev == '(':
            stack.pop()
            result += len(stack)
            prev = s

        else:
            result += 1
            stack.pop()
            prev = s
print(result)