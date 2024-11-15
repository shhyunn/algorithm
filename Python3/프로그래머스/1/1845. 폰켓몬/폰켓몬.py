def solution(nums):
    answer = 0
    dict = {}
    
    for n in nums:
        if n in dict.keys():
            dict[n] += 1
        else:
            dict[n] = 1
    
    answer = min(len(nums) // 2, len(dict.keys()))
    return answer