def solution(word):
    answer = 0
    dict = {"A" : 0, "E": 1, "I": 2, "O": 3, "U":4}
    
    for i, w in enumerate(word):
        diff = dict[w] - dict["A"]
        s = 1
        for _ in range(diff):
            for j in range(0,5-i):
                s  += 5 ** j
        answer += s
        
    return answer