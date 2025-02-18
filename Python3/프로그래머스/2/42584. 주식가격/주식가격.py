def solution(prices):
    #가격이 떨어지지 않은 기간은 몇초인가?
    stack = []
    answer = [0 for _ in range(len(prices))]
    for i, p in enumerate(prices):
        if not stack:
            stack.append(i)
            continue
        
        if prices[stack[-1]] <= p:
            stack.append(i)
        else:
            #마지막 스택 값보다 작을 경우
            while stack:
                if prices[stack[-1]] > p:
                    l = stack.pop()
                    answer[l] = i - l
                else:
                    break
            stack.append(i)
    while stack:
        l = stack.pop()
        answer[l] = len(prices) - l - 1
    
    return answer
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = [0] * len(prices)
#     stack = []
    
#     for i,p in enumerate(prices):
#         if not stack:
#             stack.append((i,p))
#             continue
        
#         if stack[-1][1] <= p:
#             stack.append((i,p))
#             continue
        
#         while stack and stack[-1][1] > p:
#             ti, tp = stack.pop()
#             answer[ti] = i-ti
#         stack.append((i,p))
    
#     while stack:
#         ti, tp = stack.pop()
#         answer[ti] = len(prices) - ti - 1
        
#     return answer