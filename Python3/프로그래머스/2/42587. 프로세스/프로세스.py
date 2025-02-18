def solution(priorities, location):
    process = [key for key in range(len(priorities))]
    
    locations = [0 for _ in range(len(priorities))]
    
    stack = []
    sequence = 1
    while process:
        value = process.pop(0)
        
        skip = False
        for other in process:
            if priorities[value] < priorities[other]:
                process.append(value)
                skip = True
                break
        
        if skip:
            continue
        
        locations[value] = sequence
        sequence += 1
    
    return locations[location]
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = [0] * len(priorities)
#     sequence = 1
#     queue = [i for i in range(len(priorities))]
    
#     while queue:
#         result = 0
#         p = queue.pop(0)
#         for item in queue:
#             if priorities[item] > priorities[p]:
#                 queue.append(p)
#                 result = 1
#                 break
#         if result == 0:
#             answer[p] = sequence
#             sequence += 1
        
#     return answer[location]