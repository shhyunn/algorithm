from itertools import combinations_with_replacement

def get_cur_point(apeach, lion):
    apeach_point = 0
    lion_point = 0
    
    for i in range(11):
        if apeach[i] == 0 and lion[i] == 0:
            continue
        if apeach[i] >= lion[i]:
            apeach_point += 10 - i
        else:
            lion_point += 10 - i
            
    return lion_point - apeach_point        


def solution(n, info):
    best_point = 0
    best_result = [0] * 11
    
    for comb in combinations_with_replacement(range(11), n):
        cur_result = [0] * 11
        
        for num in comb:
            cur_result[num] += 1
            
        cur_point = get_cur_point(info, cur_result) 
        if (cur_point > best_point) or (cur_point == best_point and cur_result[::-1] > best_result[::-1]):
            best_point = cur_point
            best_result = cur_result[:] # deepcopy
        
    return ([-1] if best_point == 0 else best_result)



# def solution(n, info):
#     #전 우승자인 라이언에게 패널티
#     # 어피치가 n발 -> 라이언이 n발
#     #동률일 경우 어피치가 가져감
#     #n발을 다 쏜 후 ->라이언이 화살을 쏠 차례, 가장 큰 점수차로 이기기 위해 어떤 과녁 점수에 맞혀야 하는가?
#     #여러가지일 경우, 가장 낮은 점수를 더 많이 맞힌 경우를 return
#     answer = [0 for _ in range(11)]
    
#     for 
#     #그러면 가장 최고점부터 어피치보다 더 많게 가져가게끔..  -> 백트래킹
    
    
    
#     return answer