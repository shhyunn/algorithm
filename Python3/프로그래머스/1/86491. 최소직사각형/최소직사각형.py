def solution(sizes):
    w = 0
    h = 0
    
    for size in sizes:
        [a,b] = size
        if a > b:
            w = max(w,a)
            h = max(h,b)
        else:
            w = max(w,b)
            h = max(h,a)
    
    answer = w * h
        
        
        
    return answer