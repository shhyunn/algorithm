from collections import defaultdict

def solution(phone_book):
    answer = True
    dic = defaultdict(int)
    
    for phone in phone_book:
        dic[phone] = 1
    
    for p in phone_book:
        temp = ""
        for i in p:
            temp += i
            if temp in dic and temp != p:
                return False
    return answer
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     answer = True
#     dict = {}
    
#     for phone in phone_book:
#         dict[phone] = 1
    
#     for phone in phone_book:
#         temp = ""
#         for p in phone:
#             temp += p
#             if temp in dict and temp != phone:
#                 return False
            