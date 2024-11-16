def solution(prices):
    answer = [0] * len(prices)
    stack = []
    
    for i,p in enumerate(prices):
        if not stack:
            stack.append((i,p))
            continue
        
        if stack[-1][1] <= p:
            stack.append((i,p))
            continue
        
        while stack and stack[-1][1] > p:
            ti, tp = stack.pop()
            answer[ti] = i-ti
        stack.append((i,p))
    
    while stack:
        ti, tp = stack.pop()
        answer[ti] = len(prices) - ti - 1
        
    return answer