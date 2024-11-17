def solution(array, commands):
    answer = []
    
    for command in commands:
        [i,j,k] = command
        temp_array = array[i-1:j]
        temp_array.sort()
        answer.append(temp_array[k-1])
    
    return answer