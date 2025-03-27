from itertools import permutations
import sys

input = sys.stdin.readline

N = int(input())


for p in permutations(range(1,N+1), N):
	print(" ".join(map(str, p)))

