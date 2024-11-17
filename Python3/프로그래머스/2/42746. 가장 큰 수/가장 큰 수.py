# def solution(numbers):
#     numbers = [str(i) for i in numbers]
#     numbers = sorted(numbers, key= lambda item: item * 3, reverse=True)
#     answer = "".join(numbers)
#     return answer

def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x*3, reverse=True)
    return str(int(''.join(numbers)))
    
