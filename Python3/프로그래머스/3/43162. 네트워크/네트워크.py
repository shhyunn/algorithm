from collections import deque
def solution(n, computers):
    answer = 0
    visited = [False] * n
    
    for i in range(n):
        if visited[i]: #이미 방문했으면 패스
            continue
        visited[i] = True
        answer += 1
        stack = deque([i])
        while stack:
            s = stack.popleft()
            for j in range(n):
                if s != j and computers[s][j] == 1 and not visited[j]:
                    visited[j] = True
                    stack.append(j)
                       
    return answer