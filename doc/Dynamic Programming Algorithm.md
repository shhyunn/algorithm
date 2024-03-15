# Dynamic Programming (동적 계획법)
* 하나의 큰 문제를 여러 개의 작은 문제로 나누어서 그 결과를 저장하여 다시 큰 문제를 해결할 때 사용
* 그 답을 저장하고 재활용
* 겹치는 부분 문제와 최적 부분 구조 조건을 만족해야 함 <br />
  -> 동일한 작은 문제들이 반복하여 나타나는 경우에 사용이 가능, 부분 문제의 최적 결과 값을 사용해 전체 문제의 최적 결과를 낼 수 있는 경우


  ## 문제 예시 코드 (백준 17070번)
  ```python3
  import sys
  input = sys.stdin.readline
  N = int(input())
  arr = []
  for _ in range(N):
      temp = list(map(int, input().split()))
      arr.append(temp)
      #1,1괴 1,2는 항상 빈칸 (파이프 현재 위치)
      #n,n으로 이동시키는 방법의 개수
  
  dp = [[[0 for _ in range(3)] for _ in range(N)] for _ in range(N)]
  dp[0][1][0] = 1
  for i in range(N):
      for j in range(N):
          if i == 0 and j <= 1:
              continue
          if arr[i][j] == 0:
              if j-1 >= 0:
                  dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1]
  
              if i-1 >= 0 and j-1 >= 0 and arr[i-1][j] == 0 and arr[i][j-1] == 0:
                  dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]
              if i-1 >= 0:
                  dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2]
  
  print(sum(dp[N-1][N-1]))
  ```
  * 파이프가 N,N에 이동할 수 있는 모든 경우의 수 구하기였다.
  * 처음에 백트래킹 및 브루트포스 알고리즘으로 접근하였고, pypy3로 문제는 해결할 수 있었지만 시간이 상당히 오래걸렸다.
  * 이에 따라 다이나믹 프로그래밍 기법으로 다시 풀어보았고, 위치와 방향(오른쪽, 아래쪽, 대각선) 을 나타내는 3차원 배열을 이용함
  * 구현은 쉬웠는데, 다만 이게 다이나믹 프로그래밍 문제인지 판단하지 못하였다.
  * 다이나믹 프로그래밍이 필요한 문제인지 한번 판단해보고 브루트포스를 사용하자, 시간 초과는 상당히 많이 나올 수 있는 문제이다.
