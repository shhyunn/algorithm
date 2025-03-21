from collections import defaultdict
from itertools import combinations

def solution(friends, gifts):
    #이번 달까지 선물을 주고 받은 기록을 바탕으로.. 예측
    #더 많은 선물을 준 사람이 다음달에 선물을 받음
    # 없거나, 같다면, 선물 지수가 더 큰 사람이 더 작은사람에게 하나 받기
    # 선물 지수 : 준 선물 수 - 받은 선물 수
    #가장 선물을 많이 받을 친구가 받을 선물의 수
    ff = len(friends)
    dic = {name: i for i,name in enumerate(friends)}
    stats = [[0,0] for _ in range(ff)] #준 선물, 받은 선물
    
    maps = [[0 for _ in range(ff)] for _ in range(ff)]
    answer = [0 for _ in range(ff)]
    
    for g in gifts:
        a, b = g.split(" ")
        ai, bi = dic[a], dic[b]
        maps[ai][bi] += 1 #준 사람이 받은 사람에게 +1
        stats[ai][0] += 1
        stats[bi][1] += 1
    
    for ai,bi in list(combinations(range(0, ff), 2)):

        if maps[ai][bi] == maps[bi][ai]:
            sa = stats[ai][0] - stats[ai][1]
            sb = stats[bi][0] - stats[bi][1]
            
            if sa > sb :
                answer[ai] += 1
            elif sa < sb:
                answer[bi] += 1

        elif maps[ai][bi] > maps[bi][ai]: #a가 더 많이 줌
            answer[ai] += 1
        else:
            answer[bi] += 1
            
    return max(answer)