from collections import defaultdict

def solution(tickets):
    r = defaultdict(list)
    for i,j in tickets:
        r[i].append(j)
    for i in r.keys():
        r[i].sort() #오름차순으로 정렬

    s = ["ICN"]
    p = []
    while s:
        q = s[-1]
        if r[q] != []: #항공권이 있다면
            s.append(r[q].pop(0)) #스택에 가장 앞에 있는 공항 pop(오름차순)하여 스택에 추가
        else: #항공권이 없다면
            p.append(s.pop()) #스택에 마지막에 있는 요소를 pop하여 결과에 추가
    return p[::-1] #거꾸로 출력


# def solution(tickets):
#     from collections import defaultdict

#     # 그래프 생성
#     graph = defaultdict(list)
#     for start, end in tickets:
#         graph[start].append(end)

#     # 각 출발지의 목적지 리스트를 사전순으로 정렬
#     for key in graph:
#         graph[key].sort(reverse=True)  # 역순으로 정렬 (스택 활용을 위해)

#     result = []  # 결과 경로 저장 스택

#     # DFS 탐색
#     def dfs(node):
#         while graph[node]:
#             next_node = graph[node].pop()  # 사전순으로 가장 앞의 경로 선택
#             dfs(next_node)
#         result.append(node)  # 역순으로 쌓음 (나중에 뒤집기)

#     dfs("ICN")  # ICN에서 시작
#     return result[::-1]  # 역순으로 정렬된 결과 반환

# def solution(tickets):
#     dic = {}
#     visited = {}
#     for tick in tickets:
#         [start, end] = tick
#         visited[start] = False
#         visited[end] = False
        
#         if start in dic:
#             dic[start].append(end)
#         else:
#             dic[start] = [end]
    
#     for key in dic:
#         dic[key].sort(reverse=True)
        
#     res = ["ICN"]
#     stack = [("ICN", res)]
#     visited["ICN"] = True
    
#     while stack:
#         print(stack)
#         target, res_t = stack.pop() #맨 끝에서 pop
#         if len(res_t) == (len(tickets) + 1):
#             return res_t
        
#         if not target in dic or not dic[target]:
#             continue
#         print(res_t)
        
        
#         for t in dic[target]:
#             if not visited[t]:
#                 visited[t] = True
#                 res_p = res_t
#                 res_p.append(t)
#                 stack.append((t, res_p))
            
#     return []   

    # return []
    # for item in dic[current][::-1]: #ICN에서 시작하여 ICN에서 도달할 수 있는 항공들 알파벳 순
    #     res = dfs(item, dic, res, length)
    #     if len(res) == len(tickets) + 1:
    #         return res
        
        
        

# while dic and not all(not value for value in dic.values()):
#         if dic[current]:
#             current = dic[current].pop()
#             res.append(current)