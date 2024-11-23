import sys
from collections import deque
input = sys.stdin.readline

N,M = map(int, input().split())
arr = []
visited = [[[False,False] for _ in range(M)] for _ in range(N)]
for _ in range(N):
    temp = input().strip()
    arr.append(temp)

stack = deque([(1,(0,0),0)]) #거리,좌표, 벽 부수기 유무
visited[0][0][0] = True
move_x = [-1,1,0,0]
move_y =[0,0,-1,1]
res = 1e9
while stack:
    d, (x,y), flag =stack.popleft()
    if x == N-1 and y == M-1:
        res = min(res, d)
        continue

    for i in range(4):
        cx = x + move_x[i]
        cy = y + move_y[i]

        if 0 <= cx < N and 0 <= cy < M:
            if flag == 1 and not visited[cx][cy][1] and arr[cx][cy] == '0': #벽이 아닌데 벽을 이미 부쉈어, 근데 방문을 안했어
                visited[cx][cy][1] = True
                stack.append((d+1,(cx,cy),flag))
            
            elif flag == 0 and not visited[cx][cy][0] and arr[cx][cy] == '0': #벽을 안부쉈는데 아직 안갔어, 벽이 없어
                visited[cx][cy][0] = True
                stack.append((d+1,(cx,cy),flag))
            
            elif flag == 0 and not visited[cx][cy][1] and arr[cx][cy] == '1': #벽을 안부쉈고 이제 부술거야
                visited[cx][cy][1] = True
                stack.append((d+1, (cx,cy),1))

            # if flag == 1 and arr[cx][cy] == '1':
            #     continue
            # else:
            #     if not visited[cx][cy][1] and arr[cx][cy] == '1' and flag == 1: #벽을 부쉈는데, 1이 나타남
                   
            #         #heapq.heappush(stack, (d+1,(cx,cy),1))
            #     elif arr[cx][cy] == '0':
            #         if not visited[cx][cy][0] and flag == 0:
            #             visited[cx][cy][0] = True
            #             stack.append((d+1,(cx,cy),flag))

            #         elif not visited[cx][cy][1] and flag == 1:
            #             visited[cx][cy][1] = True
            #             stack.append((d+1,(cx,cy),flag))
            #             #heapq.heappush(stack, (d+1,(cx,cy),flag))

if res == 1e9:
    print(-1)
else:
    print(res)