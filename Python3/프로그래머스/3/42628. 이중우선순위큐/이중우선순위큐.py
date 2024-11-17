import heapq
def solution(operations):
    #모든 연산을 처리한 후 큐가 비어있으면 [0,0], 비어있지 않으면 [최댓값, 최솟값] 리턴
    answer = []
    q_min = []
    q_max = []
    heapq.heapify(q_min)
    heapq.heapify(q_max)
    dict = {}
    
    for s in operations:
        c, num = s.split(" ")
        
        if c == "I":
            dict[int(num)] = 1 # 값 넣기
            heapq.heappush(q_min, int(num)) #최솟값 저장 위함
            heapq.heappush(q_max, -int(num)) #최댓값 저장 위함
            
        elif c == "D":
            if num == "1" and q_max: #최댓값 삭제
                while q_max:
                    max_value = heapq.heappop(q_max)
                    if dict[-max_value] == 1:
                        dict[-max_value] = 0
                        break
                
            elif num == "-1" and q_min:
                while q_min:
                    min_value = heapq.heappop(q_min)
                    if dict[min_value] == 1:
                        dict[min_value] = 0
                        break
        
    min_value, max_value = 0,0
    while q_max:
        temp_value = heapq.heappop(q_max)
        if dict[-temp_value] == 1:
            max_value = -temp_value
            break
            
    while q_min:
        temp_value = heapq.heappop(q_min)
        if dict[temp_value] == 1:
            min_value = temp_value
            break
            
    return [max_value, min_value]
        
        
        
            
    
    
#     min_value = heapq.heappop(q_min)
    
#     if dict[min_value] == 0:
#         return [0,0]
    
#     max_value = heapq.heappop(q_max)
#     if max_value == min_value:
        
#         return [max_value, min_value]
#     elif dict[max_value] == 0:
#         return [0,0]
    
#     else:
#         return [max_value, min_value]
        