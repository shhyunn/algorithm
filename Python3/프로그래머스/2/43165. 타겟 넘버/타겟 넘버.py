from collections import deque

def solution(numbers, target):
    #n개의 음이 아닌 정수, 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만드는 방법의 수
    res = 0
    stack =deque([(0,0)]) #0번째 순서, 합 0
    
    while stack:
        i, sums = stack.popleft()
        if i == len(numbers) and sums == target:
            res += 1
            continue
        
        if i < len(numbers):
            stack.append((i+1, sums + numbers[i]))
            stack.append((i+1, sums - numbers[i]))
    
    return res
            
            
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = 0
#     stack = deque([(1, numbers[0]), (1, -numbers[0])])
#     while stack:
#         i, temp = stack.popleft()
#         if i == len(numbers):
#             if temp == target:
#                 answer += 1
#                 continue
#             else:
#                 continue
        
#         stack.append((i+1, temp+numbers[i]))
#         stack.append((i+1, temp-numbers[i]))
        
#     return answer
