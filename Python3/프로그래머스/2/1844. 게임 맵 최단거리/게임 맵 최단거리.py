from collections import deque

def solution(maps):
    answer = 0
    n = len(maps) # 행
    m = len(maps[0]) #열

    visited = [[False for _ in range(m)] for _ in range(n)]
    visited[0][0] = True
    stack = deque([(0,0,1)])
    
    while stack:
        x, y, cnt = stack.popleft()
        if x == n-1 and y == m-1:
            print("cnt", cnt)
            return cnt
        
        if x < n-1 and maps[x+1][y] == 1 and not visited[x+1][y]: #동쪽 이동
            visited[x+1][y] = True
            stack.append((x+1, y, cnt+1))
            
        if x > 0 and maps[x-1][y] == 1 and not visited[x-1][y]:
            visited[x-1][y] = True
            stack.append((x-1, y, cnt+1))
            
        if y < m-1 and maps[x][y+1] == 1 and not visited[x][y+1]:
            visited[x][y+1] = True
            stack.append((x, y+1, cnt+1))
            
        if y > 0 and maps[x][y-1] == 1 and not visited[x][y-1]:
            visited[x][y-1] = True
            stack.append((x, y-1, cnt+1))
            
    return -1 