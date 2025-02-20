def solution(sizes):
    
    w,h = 0,0
    for tw,th in sizes:
        cw = min(tw,th)
        ch = max(tw,th)
        
        w = max(w,cw)
        h = max(h,ch)
    
    return w*h
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     w = 0
#     h = 0
    
#     for size in sizes:
#         [a,b] = size
#         if a > b:
#             w = max(w,a)
#             h = max(h,b)
#         else:
#             w = max(w,b)
#             h = max(h,a)
    
#     answer = w * h
        
        
        
#     return answer