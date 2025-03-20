INF = int(1e12)

def solution(alp, cop, problems):
    problems.append([0,0,1,0,1])
    problems.append([0,0,0,1,1])
    
    
    max_alp = max([p[0] for p in problems] + [alp])
    max_cop = max([p[1] for p in problems] + [cop])
    
    dp = [[INF for _ in range(max_cop+1)] for _ in range(max_alp+1)]
    dp[alp][cop] = 0
    
    for i in range(alp, max_alp+1):
        for j in range(cop, max_cop+1):
            for p in problems:
                if p[0] <= i and p[1] <= j:
                    next_i = min(max_alp, i + p[2])
                    next_j = min(max_cop, j + p[3])
                    
                    dp[next_i][next_j] = min(dp[next_i][next_j], dp[i][j] + p[4])
    
    return dp[max_alp][max_cop]


















# def solution(alp, cop, problems):
#     problems.append([0, 0, 1, 0, 1])
#     problems.append([0, 0, 0, 1, 1])
    
#     target_alp = max([problem[0] for problem in problems] + [alp])
#     target_cop = max([problem[1] for problem in problems] + [cop])
#     #만들어야 하는 알고력, 코딩력 최댓값
    
#     # solve (dp : bottom up)
#     dp = [[INF] * (target_cop + 1) for _ in range(target_alp + 1)]
#     dp[alp][cop] = 0 #초기값 세팅
    
#     for ap in range(alp, target_alp + 1):
#         for cp in range(cop, target_cop + 1): #각 알고력, 코딩력마다 문제 반복
#             for aq, cq, ad, cd, cost in problems:
#                 if ap >= aq and cp >= cq: #문제를 풀 수 있는 경우라면
#                     nxt_ap = min(target_alp, ap + ad) #만약 타겟값 초과라면 타겟값으로 세팅
#                     nxt_cp = min(target_cop, cp + cd) #현재 알고, 코딩력에서 갱신되는 값 계속해서 갱신
#                     dp[nxt_ap][nxt_cp] = min(dp[nxt_ap][nxt_cp], dp[ap][cp] + cost)
        
#     return dp[target_alp][target_cop]
