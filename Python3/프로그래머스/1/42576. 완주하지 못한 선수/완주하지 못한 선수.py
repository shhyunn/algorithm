from collections import defaultdict
def solution(participant, completion):
    dic = defaultdict(int)
    temp = 0
    for s in participant:
        temp += hash(s)
        dic[hash(s)] = s
    
    for c in completion:
        temp -= hash(c)
    
    res = dic[temp]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     dict = {}
#     temp = 0
#     for p in participant:
#         temp += hash(p)
#         dict[hash(p)] = p 
    
#     for c in completion:
#         temp -= hash(c)
#     res = dict[temp]
        
    
        
    return res