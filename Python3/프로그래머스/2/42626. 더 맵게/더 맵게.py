import heapq

def solution(scoville, K):
    answer = 0  
    heapq.heapify(scoville)
    
    while scoville:
        if scoville[0] >= K:
            break
        
        if len(scoville) < 2:
            answer = -1
            break
        
        a = heapq.heappop(scoville) #가장 안매운 음식
        b = heapq.heappop(scoville) #두번째로 안매운 음식
        
        c = a + b*2
        heapq.heappush(scoville, c)
        answer += 1
            
    return answer