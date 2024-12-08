import sys
input = sys.stdin.readline

N = int(input())

arr = []

for _ in range(N):
    temp = list(input().strip())
    arr.append(temp)

def checkCurMaxNum():
    max_cnt = 1  # total_max_cnt
    for i in range(N):
        # 가로 먼저 확인
        cnt = 1
        for j in range(1, N):
            if arr[i][j] == arr[i][j - 1]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(cnt, max_cnt)
        # 세로 확인
        cnt = 1
        for j in range(1, N):
            if arr[j][i] == arr[j - 1][i]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(cnt, max_cnt)

    return max_cnt


# 오른쪽 swap, 아래쪽 swap
result = 1
for i in range(N):
    for j in range(N - 1):
        # 오른쪽 swap
        if j + 1 < N and arr[i][j] != arr[i][j + 1]:
            arr[i][j], arr[i][j + 1] = arr[i][j + 1], arr[i][j]  # swap
            # 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고름
            result = max(result, checkCurMaxNum())
            arr[i][j], arr[i][j + 1] = arr[i][j + 1], arr[i][j]  # 다시 되돌리기
        # 왼쪽 swap
        if i + 1 < N and arr[i][j] != arr[i + 1][j]:
            arr[i][j], arr[i + 1][j] = arr[i + 1][j], arr[i][j]  # swap
            # 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고름
            result = max(result, checkCurMaxNum())
            arr[i][j], arr[i + 1][j] = arr[i + 1][j], arr[i][j]  # 다시 되돌리기

print(result)
