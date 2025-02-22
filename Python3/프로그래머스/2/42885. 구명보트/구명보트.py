from collections import deque #양방향 큐를 사용해서 뭐함?

def solution(people, limit):
    #구명보트는 한번에 최대 2명, 구명보트를 최대한 적게 사용하여 모든 사람을 구출
    people.sort()
    people = deque(people)
    ans = 0
    
    while people:
        a = people.pop()
        if people and people[0] + a <= limit:
            people.popleft()
        ans += 1
    
    return ans
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     #구명보트를 최대한 적게 사용하여 모든 사람을 구출함
#     # 모든사람을 구출하기 위한 필요한 구명보트 개수의 최솟값
#     people = deque(sorted(people))
    
#     current = 0
#     while people:
#         #무게가 적게 나가는 사람부터 검사
#         if len(people) > 1:
#             if people[0] + people[-1] <= limit:
#                 people.popleft()
#                 people.pop()
#             else:
#                 people.pop()
#             current += 1
            
#         else:
#             people.pop()
#             current += 1
    
#     answer = 0
#     return current