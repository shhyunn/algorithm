import sys, math
input = sys.stdin.readline

N = input().strip()

nums = [0 for _ in range(10)]

for i in N:
    i = int(i)
    nums[i] += 1

nums[6] = math.ceil((nums[6] + nums[9]) / 2)
nums[9] = 0
print(max(nums))