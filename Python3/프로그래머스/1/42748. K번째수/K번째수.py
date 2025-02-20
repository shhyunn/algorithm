def solution(array, commands):
    #i번째 숫자부터 j번째 숫자까지 자르고 정렬 -> K번째 있는 수
    #i,j,k
    answer = []
    for i,j,k in commands:
        temp = array[i-1:j]
        temp.sort()
        answer.append(temp[k-1])
    
    return answer
        
    
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = []
    
#     for command in commands:
#         [i,j,k] = command
#         temp_array = array[i-1:j]
#         temp_array.sort()
#         answer.append(temp_array[k-1])
    
#     return answer