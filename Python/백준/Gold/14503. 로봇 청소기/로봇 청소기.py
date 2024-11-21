import sys
input = sys.stdin.readline

dic = {0: (-1,0), 1:(0,1), 2: (1,0), 3:(0,-1)}

N, M = map(int,input().strip().split(" "))
maps = [[0 for _ in range(M)] for _ in range(N)]

r,c,d = map(int, input().strip().split(" "))

for i in range(N):
    temp = list(map(int, input().strip().split(" ")))
    for j, item in enumerate(temp):
        maps[i][j] = item

stop = False
current_r = r
current_c = c
current_d = d
cnt = 0

while not stop:
    if maps[current_r][current_c] == 0:
        maps[current_r][current_c] = 2
        cnt += 1
    find = 0
    for i in range(4):
        cx, cy = dic[i]
        dx = current_r + cx
        dy = current_c + cy

        if 0 <= dx < N and 0 <= dy < M and maps[dx][dy] == 0:
            find = 1
            break
    if find == 0:
        cx, cy = dic[(current_d+2)%4]
        dx = current_r + cx
        dy = current_c + cy
        if 0<= dx < N and 0<= dy < M and maps[dx][dy] != 1: #청소되지 않은 빈칸>이 없는 경우
            current_r = dx
            current_c = dy

        else:
            stop = True
    else:
        current_d = (current_d+3) % 4
        cx,cy = dic[current_d]
        dx = current_r + cx
        dy = current_c + cy
        if 0 <= dx < N and 0 <= dy < M and maps[dx][dy] == 0:
            current_r = dx
            current_c = dy
print(cnt)