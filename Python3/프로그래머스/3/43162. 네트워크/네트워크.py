from collections import deque

def solution(n, computers):
    #네트워크의 개수
    visited = [False] * n
    res = 0
    
    for k in range(n):
        if visited[k]:
            continue
        visited[k] = True
        stack = deque([k])
        res += 1
        while stack:
            curr = stack.popleft() 
            for i,v in enumerate(computers[curr]):
                if not visited[i] and v == 1:
                    visited[i] = True
                    stack.append(i)
    return res
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = 0
#     visited = [False] * n
    
#     for i in range(n):
#         if visited[i]: #이미 방문했으면 패스
#             continue
#         visited[i] = True
#         answer += 1
#         stack = deque([i])
#         while stack:
#             s = stack.popleft()
#             for j in range(n):
#                 if s != j and computers[s][j] == 1 and not visited[j]:
#                     visited[j] = True
#                     stack.append(j)
                       
#     return answer