import sys
sys.setrecursionlimit(10 ** 4)
input = sys.stdin.readline

k = int(input())

signs =list(input().strip().split(" "))
res = []
visited = [False for _ in range(10)]

def dfs(s, cnt):
    global visited, res
    if cnt == k+1:
        res.append(s)
        return

    for i, v in enumerate(visited):
        if not v:
            visited[i] = True
            if cnt >= 1:
                t = signs[cnt-1]
                if t == "<" and int(s[cnt-1]) < i:
                    dfs(s+str(i), cnt+1)
                if t == ">" and int(s[cnt-1]) > i:
                    dfs(s+str(i), cnt+1)
            else:
                dfs(s+str(i), cnt+1)

            visited[i] = False

dfs("", 0)
res.sort()
print(res[-1])
print(res[0])