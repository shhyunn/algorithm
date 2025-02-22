def solution(money):
    dp1 = [ 0 for _ in range(len(money))] #첫 집을 턴 경우
    dp1[0] = money[0]
    dp1[1] = money[0]
    
    dp2 = [0 for _ in range(len(money))] #첫 집을 털지 않은 경우
    dp2[1] = money[1]
    
    for i in range(2, len(money)-1):
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1])
    
    for i in range(2, len(money)):
        dp2[i] = max(dp2[i-2]+money[i], dp2[i-1])
        
    answer = max(dp1[len(money)-2], dp2[len(money)-1])
    
    return answer
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = 0
#     dp1 = [0 for _ in range(len(money))]

#     dp1[0] = money[0]
#     dp1[1] = money[0]
#     for i in range(2, len(money)-1):
#         dp1[i] = max(dp1[i-2] + money[i], dp1[i-1])
    
#     dp2 = [0 for _ in range(len(money))]
#     dp2[0] = 0 #첫집을 털지 않은 경우
#     dp2[1] = money[1]
    
#     for i in range(2,len(money)):
#         dp2[i] = max(dp2[i-2] + money[i], dp2[i-1])
    
#     answer = max(dp1[len(money)-2],dp2[len(money)-1])
#     return answer