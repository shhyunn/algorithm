from itertools import combinations
import sys

input = sys.stdin.readline

while True:
	temp = list(map(int, input().split(" ")))
	N = temp.pop(0)

	if N == 0:
		break
	pp = combinations(temp, 6)

	for p in pp:
		print(" ".join(map(str, p)))
	print("")
