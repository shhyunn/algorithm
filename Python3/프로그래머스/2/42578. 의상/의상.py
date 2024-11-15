def solution(clothes):
    dict = {}
    for cloth, category in clothes:
        if category in dict:
            dict[category] += 1
        else:
            dict[category] = 1
    
    answer = 1
    for key in dict.keys():
        answer *= (dict[key] + 1)
        
    answer -= 1
    return answer