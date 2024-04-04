def solve(n, arr):
	# 앞에서 부터 가장 긴 증가하는 수열 구하기 
    dp = [0] * n
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[j] + 1, dp[i])
                
	# 뒤집어서 가장 긴 증가하는 수열 구하기 
    dp_back = [0] * n
    arr_back = arr[::-1]
    for i in range(1, n):
        for j in range(i):
            if arr_back[i] > arr_back[j]:
                dp_back[i] = max(dp_back[j] + 1, dp_back[i])
	# 구한 두 dp값들이 최대가 되는 값 구하기
    answer = 0
    for i in range(n):
    	# 뒤에서 부터 구한 값들은 다시 뒤집어서 최댓값 갱신
        answer = max(answer, dp[i] + dp_back[::-1][i])
    return answer + 1

# input
n = int(input())
arr = list(map(int, input().split()))
print(solve(n, arr))