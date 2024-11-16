def solution(priorities, location):
    answer = [0] * len(priorities)
    sequence = 1
    queue = [i for i in range(len(priorities))]
    
    while queue:
        result = 0
        p = queue.pop(0)
        for item in queue:
            if priorities[item] > priorities[p]:
                queue.append(p)
                result = 1
                break
        if result == 0:
            answer[p] = sequence
            sequence += 1
        
    return answer[location]