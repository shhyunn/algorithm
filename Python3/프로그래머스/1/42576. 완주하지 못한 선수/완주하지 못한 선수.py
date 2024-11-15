def solution(participant, completion):
    
    dict = {}
    temp = 0
    for p in participant:
        temp += hash(p)
        dict[hash(p)] = p 
    
    for c in completion:
        temp -= hash(c)
    res = dict[temp]
        
    
        
    return res