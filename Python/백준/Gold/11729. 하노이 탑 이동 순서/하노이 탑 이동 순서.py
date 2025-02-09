import sys
input = sys.stdin.readline

N = int(input())
#A번째 탑의 가장 위에 있는 원반을 B번째 탑으로 이동

arr = []

def recur(n, start, dest, mid):
    global arr
    if n == 1:
        arr.append(str(start) + " " + str(dest))
        return

    recur(n-1, start, mid, dest)
    arr.append(str(start) + " " + str(dest))
    recur(n-1, mid, dest, start)

recur(N, 1, 3, 2)
print(len(arr))
for s in arr:
    print(s)
