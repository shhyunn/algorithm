import sys
input = sys.stdin.readline

strr = input().strip()

stack = []

dict = {'+':1, '-':1, '*':2, '/':2, '(':0}
res = ''

for s in strr:
    if ord('A') <= ord(s) and ord(s) <= ord('Z'):
        res += s

    elif s == '(':
        stack.append(s)
    elif s == ')':
        while stack and stack[-1] != '(':
            res += stack.pop()
        stack.pop()

    else:
        while stack and dict[s] <= dict[stack[-1]]:
            res += stack.pop()
        stack.append(s)

while stack:
    res += stack.pop()

print(res)
