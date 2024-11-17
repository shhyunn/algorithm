from itertools import permutations

def solution(k, dungeons):
    #최소필요피로도: 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도
    #소모피로도: 던전을 탐험한 후 소모되는 피로도
    #최대한 많이 탐험, 현재 피로도 k, 각 던전별 최소 필요 피로도 + 소모 피로도 -> 최대 던전 수는?
    
    dungeons = sorted(dungeons, key=lambda item: item[0], reverse=True)
    sequences = list(permutations(range(0,len(dungeons))))
    
    
    answer = 0
    for sequence in sequences:
        cnt = 0
        current = k
        for s in sequence: #던전 순서
            [min_value, minus_value] = dungeons[s]
            if current < min_value:
                break
            cnt += 1
            current -= minus_value
        
        answer = max(cnt, answer)
    
    return answer