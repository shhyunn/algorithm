import sys
input = sys.stdin.readline

S = list(input().strip())
T = list(input().strip())

switch =False

while T:
    if T[-1] == "A":
        T.pop()
    elif T[-1] == "B":
        T.pop()
        T.reverse()

    if T == S:
        switch = True
        break

if switch:
    print(1)
else:
    print(0)
