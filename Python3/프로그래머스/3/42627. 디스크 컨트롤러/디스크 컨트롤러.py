import heapq

def solution(jobs):
    #작업 번호, 작업 요청 시각, 작업 소요 시간
    #작업을 안하고, 대기 큐가 비어있지 않다면, 가장 우선순위가 높은 작업을 대기큐에서 꺼내서 작업 진행
    #우선순위 - 작업 소요 시간이 짧고, 작업 요청시각이 빠르고, 작업 번호가 작은 것
    #작업 마치고, 요청 시점이 겹친다면, 요청이 들어온 작업을 대기 큐에 저장 후, 우선순위가 높은 작업을 대기 큐에서 꺼내서 시킴
    q = []
    dict = {}
    heapq.heapify(q)
    sec = 0
    block = 0
    answer = 0
    
    for i, item in enumerate(jobs):
        if item[0] in dict:
            dict[item[0]].append((item[1], item[0], i))
        else:
            dict[item[0]] = [(item[1], item[0], i)]
    
    while dict or q:
        if block > 0:
            block -= 1
        
        if sec in dict: #현재 시각에 들어오는 작업이 있을 경우
            for ls in dict[sec]:
                heapq.heappush(q, ls)
            dict.pop(sec)
            
        if block == 0 and q:
            current = heapq.heappop(q) #현재 가장 우선순위가 높은 작업 pop
            block = current[0]
            answer += (sec - current[1]) + block
                
        sec += 1
        
    
    answer //= len(jobs)
    
    return answer