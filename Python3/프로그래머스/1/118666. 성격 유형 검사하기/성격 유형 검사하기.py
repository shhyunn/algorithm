from collections import defaultdict
def solution(survey, choices):
    
    answer = ''
    dic = defaultdict(int)
    score = [0,3,2,1,0,1,2,3]
    for i in range(len(survey)):
        c = choices[i]
        s = survey[i]
        
        if c == 4:
            continue
        
        dic[s[c//4]] += score[c]
    
    for t in ['RT', 'CF', 'JM', 'AN']:
        a,b = t[0], t[1]
        
        if dic[a] == dic[b]:
            answer += a if a < b else b
        else:
            answer += a if dic[a] > dic[b] else b        
        
    return answer