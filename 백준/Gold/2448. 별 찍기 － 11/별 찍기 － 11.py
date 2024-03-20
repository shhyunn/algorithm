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

# def recur(N,r,cnt):
#     if N == 0:
#         return
#     #시작지점 지정
#     if N % 3 == 0:
#         recur(N-1,r+1,cnt)
#         for _ in range(cnt):
#             strr = " "*r+"*****"+" "*r
#             print(strr, end=" ")
            
#     elif N % 3 == 2:
#         recur(N-1,r+1,cnt)
#         for _ in range(cnt):
#             strr = " "*r+"* *"+" "*r
#             print(strr,end=" ")
    
#     elif N % 3 == 1:
#         recur(N-1,r+1,cnt//2)
#         for _ in range(cnt):
#             strr = " "*r+"*"+" "*r
#             print(strr, end=" ")
#     print()

# recur(N,0,N//3)