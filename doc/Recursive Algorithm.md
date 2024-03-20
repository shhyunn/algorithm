# Recursive Algorithm
* 하나의 함수에서 자기 자신을 다시 호출하여 작업을 수행하는 알고리즘
* 재귀함수는 특정 입력에 대해서 자기 자신을 호출하지 않고 종료해야 함 -> 무한 루프 고려

## 예시 문제 코드(백준 2448번)
```python3
import sys
input = sys.stdin.readline
N = int(input())

stars = [[' ']*2*N for _ in range(N)]

def recur(i,j,size):
    if size == 3:
        stars[i][j] = '*'
        stars[i+1][j-1] = stars[i+1][j+1] = '*'
        for k in range(-2,3):
            stars[i+2][j-k] = "*"
    else:
        ns = size//2
        recur(i,j,ns)
        recur(i+ns, j-ns,ns)
        recur(i+ns, j+ns,ns)

recur(0,N-1,N)
for star in stars:
    print("".join(star))
```
* 가장 대표적인 별 찍기 문제이다. 일반 문제와는 다르게 재귀 문제이지만 조금 생각이 더 필요했다.
* 3개의 꼭짓접을 중심으로, 사이즈가 3일 때까지 계속해서 재귀적으로 함수를 호출하는게 특징이다.
* 재귀 문제는 단순한 문제만 많이 풀어봐 조금 까다로운 재귀 문제 풀이에 어려움을 겪었는데, 관련 문제를 많이 풀어볼 필요가 있는 것 같다.
