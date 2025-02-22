from collections import deque

def solution(maps):
    #상대팀 진영을 먼저 파괴하면 이기는 게임
    #동, 서, 남, 북 방향으로 한칸씩 이동
    #상대팀 진영에 도착하기 위해 지나가야 하는 칸의 최솟값
    ln = len(maps)
    lm =len(maps[0])
    
    visited = [[0 for _ in range(lm)] for _ in range(ln)]
    move = [(0,1), (1,0), (-1,0), (0,-1)]
    stack = deque([(0,0,1)]) #i,j,s
    res = -1
    visited[0][0] = True
    
    while stack:
        i,j,s = stack.popleft()
        if i == ln-1 and j == lm-1:
            return s
        
        for dx, dy in move:
            cx = i + dx
            cy = j + dy
            if 0 <= cx < ln and 0 <= cy < lm and not visited[cx][cy] and maps[cx][cy] == 1:
                visited[cx][cy] = True
                stack.append((cx,cy,s+1))
    
    return res
            
        
            
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = 0
#     n = len(maps) # 행
#     m = len(maps[0]) #열
#     dx = [1,-1,0,0]
#     dy = [0,0,1,-1]

#     visited = [[False for _ in range(m)] for _ in range(n)]
#     visited[0][0] = True
#     stack = deque([(0,0,1)])
    
#     while stack:
#         x, y, cnt = stack.popleft()
        
#         if x == n-1 and y == m-1:
#             return cnt

#         for cx, cy in zip(dx,dy):
#             nx, ny = x+cx, y+cy
#             if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and maps[nx][ny] ==1 :
#                 visited[nx][ny] = True
#                 stack.append((nx,ny,cnt+1))  
            
#     return -1 