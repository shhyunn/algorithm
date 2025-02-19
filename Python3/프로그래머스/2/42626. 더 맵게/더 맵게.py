import heapq

def solution(scoville, K):
    #모든 음식의 스코빌지수를 K이상으로 만들기 위해 섞어야 하는 최소 횟수?
    stack = []
    res = 0
    heapq.heapify(scoville)
    
    while scoville:
        if scoville[0] >= K:
            break

        if len(scoville) < 2:
            return -1
        a = heapq.heappop(scoville)
        b = heapq.heappop(scoville)
        c = a + b * 2
        heapq.heappush(scoville, c)
        res += 1
    
    return res
    
    
    
    
    
    
    
    
    
    
    
#     answer = 0  
#     heapq.heapify(scoville)
    
#     while scoville:
#         if scoville[0] >= K:
#             break
        
#         if len(scoville) < 2:
#             answer = -1
#             break
        
#         a = heapq.heappop(scoville) #가장 안매운 음식
#         b = heapq.heappop(scoville) #두번째로 안매운 음식
        
#         c = a + b*2
#         heapq.heappush(scoville, c)
#         answer += 1
            
#     return answer