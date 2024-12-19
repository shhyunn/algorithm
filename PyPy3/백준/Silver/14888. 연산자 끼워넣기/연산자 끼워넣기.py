import sys
from itertools import permutations

input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().strip().split(" ")))
sign = list(map(int, input().strip().split(" ")))
sign_arr = []
dic = ["+","-","*","/"]

signs = ""
for i, v in enumerate(sign):
    for _ in range(v):
        sign_arr+=str(i)


res = permutations(sign_arr, N-1)
all_permutations = list(res)

min_value = float('inf')
max_value = -float('inf')

for ap in all_permutations:
    temp = arr[0]
    for i, v in enumerate(arr[1:]):
        if ap[i-1] == '0':
            temp += v
        elif ap[i-1] == '1':
            temp -= v
        elif ap[i-1] == '2':
            temp *= v
        else:
            if temp < 0:
                temp = -temp
                temp = -(temp//v)
            else:
                temp //= v
    
    min_value = min(min_value, temp)
    max_value = max(max_value, temp)

print(int(max_value))
print(int(min_value))

