def solution(number, k):
    #어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자
    #뒷 수가 현재 수보다 크다면 제거하는게 맞음 이걸 반복적으로...
    
    curr = k
    stack = []
    for i, number in enumerate(number):
        if not stack:
            stack.append(number)
            continue
        
        while stack and stack[-1] < number and curr > 0:
            stack.pop()
            curr -= 1
            
        else:
            stack.append(number)
    
    while curr > 0:
        stack.pop()
        curr -= 1
    
    return "".join(stack)
            
            
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     stack = []
#     for n in number:
#         if not stack:
#             stack.append(n)
#             continue
#         while stack and n > stack[-1] and k > 0:
#             stack.pop()
#             k -= 1
        
#         stack.append(n)
        
#     while k > 0:
#         stack.pop()
#         k -= 1
            
#     answer = ''.join(stack)
#     return answer