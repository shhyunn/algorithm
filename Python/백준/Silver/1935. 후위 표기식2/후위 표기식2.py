import sys
input = sys.stdin.readline

N = int(input().strip())
strr = input().strip()
values = []

for _ in range(N):
    values.append(int(input().strip()))

stack = []

for s in strr:
    if 'A' <= s and s <= 'Z':
        stack.append(values[ord(s)-65])
        continue

    elif s == '+':
        temp = stack.pop() + stack.pop()
        stack.append(temp)

    elif s == '*':
        temp = stack.pop() * stack.pop()
        stack.append(temp)

    elif s == '/':
        b = stack.pop()
        a = stack.pop()
        temp = a / b
        stack.append(temp)

    elif s == '-':
        b = stack.pop()
        a = stack.pop()
        temp = a - b
        stack.append(temp)


print("{:.2f}".format(stack.pop()))
