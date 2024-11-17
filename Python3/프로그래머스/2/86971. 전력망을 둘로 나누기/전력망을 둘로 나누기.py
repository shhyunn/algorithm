def solution(n, wires):
    #n개의 송전탑이 전선을 통해 트리로 연결, 2개로 분할, 송전탑 개수를 최대한 비슷하게..
    #송전탑 개수의 차이 return
    #n: 송전탑 개수
    #wires: n-1 길이의 2차원 배열, 어떤 송전탑이 연결되어 있는지 정보 전달
    dict = {}
    answer = -1
    for wire in wires:
        [a,b] = wire
        if a in dict:
            dict[a].append(b)
        elif a not in dict:
            dict[a] = [b]
        
        if b in dict:
            dict[b].append(a)
        elif b not in dict:
            dict[b] = [a]
    
    max_value = 0
    max_key = []
    
    for k in list(dict.keys()):
        if len(dict[k]) > max_value:
            max_value = len(dict[k])
            max_key = [k]
        elif len(dict[k]) == max_value:
            max_key.append(k)
    
    answer = n
    
    for key in dict.keys():
        for w in dict[key]:
            visited = [0] * (n+1)
            visited[key] = 1
            stack = [w]
            cnt = 0
            visited[w] = 1
            while stack:
                p = stack.pop(0)
                visited[p] = 1
                cnt += 1
                for t in dict[p]:
                    if not visited[t]:
                        stack.append(t)
                
            answer = min(abs(cnt-(n-cnt)),answer)
            
    return answer