def solution(lottos, win_nums):
    len_lottos = len(lottos)
    zero, correct = 0,0
    
    for i in range(len_lottos):
        if lottos[i] == 0:
            zero += 1
            continue
        
        if lottos[i] in win_nums:
            correct += 1
    
    best = len_lottos-(zero + correct)+1 if len_lottos-(zero + correct)+1 <= 6 else 6
    worst = len_lottos-correct+1 if len_lottos-correct+1 <= 6 else 6
    answer = [best, worst]
    return answer