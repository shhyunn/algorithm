import sys
input = sys.stdin.readline
R,C = map(int, input().split())
#1,1에는 말이 놓여있음, 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 함
#최대한 몇 칸 지날 수 있는가?
arr = []
#visited = [[False for _ in range(C)] for _ in range(R)]
for _ in range(R):
    temp = input().strip()
    arr.append(temp)
    # for ch in temp:
    #     keys.append(ch)

# keys = set(keys)
# used = {key:0 for key in keys}

dx = [-1,1,0,0]
dy = [0,0,-1,1]
#used = set()
#max_val = -1

# def dfs(a,b,curr):
#     global max_val

#     max_val = max(max_val, curr)

#     for i in range(4):
#         cx = a + dx[i]
#         cy = b + dy[i]
#         if 0 <= cx < R and 0 <= cy < C and arr[cx][cy] not in used:
#             #not visited[cx][cy] and
#             #방문하자
#             #visited[cx][cy] = True
#             #used[arr[cx][cy]] += 1
#             used.add(arr[cx][cy])
#             dfs(cx,cy,curr+1)
#             used.remove(arr[cx][cy])
#             #used[arr[cx][cy]] -= 1
#             #visited[cx][cy] = False

def bfs():
    stack = set()
    stack.add((0,0,arr[0][0]))
    max_val = 0

    while stack:
        x,y,used = stack.pop()
        max_val = max(len(used),max_val)

        for i in range(4):
            cx = x + dx[i]
            cy = y + dy[i]

            if 0 <= cx < R and 0 <= cy < C and arr[cx][cy] not in used:
                stack.add((cx,cy,used+arr[cx][cy]))
    return max_val

#visited[0][0] = True
#used[arr[0][0]] += 1
#used.add(arr[0][0])
print(bfs())