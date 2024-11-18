def solution(number, k):
    stack = []
    for n in number:
        if not stack:
            stack.append(n)
            continue
        while stack and n > stack[-1] and k > 0:
            stack.pop()
            k -= 1
        
        stack.append(n)
        
    while k > 0:
        stack.pop()
        k -= 1
            
    answer = ''.join(stack)
    return answer