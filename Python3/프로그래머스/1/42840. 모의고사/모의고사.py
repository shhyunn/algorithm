def solution(answers):
    num1 = [1,2,3,4,5]
    num2 = [2,1,2,3,2,4,2,5]
    num3 = [3,3,1,1,2,2,4,4,5,5]
    
    result = [0 for _ in answers]

    for i,answer in enumerate(answers):
        if num1[(i + 5) % 5] == answer:
            result[0] += 1
            
        if num2[(i + 8) % 8] == answer:
            result[1] += 1
    
        if num3[(i + 10) % 10] == answer:
            result[2] += 1
    
    max_value = max(result)
    answer = []
    
    for i,res in enumerate(result):
        if res == max_value:
            answer.append(i+1)
    
    return answer







# def solution(answers):
#     answer = []
#     first = [1,2,3,4,5]
#     second = [2,1,2,3,2,4,2,5]
#     third = [3,3,1,1,2,2,4,4,5,5]
#     result = []
    
#     for lst in [first, second, third]:
#         cnt = 0
#         temp = 0
#         for ans in answers:
#             if lst[cnt] == ans:
#                 temp += 1
#             cnt += 1
#             if cnt == len(lst):
#                 cnt = 0
            
#         result.append(temp)
    
#     max_value = max(result)
    
#     for id in range(len(result)):
#         if result[id] == max_value:
#             answer.append(id+1)
            
#     return answer