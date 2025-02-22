from collections import deque

def solution(begin, target, words):
    #한번에 한개의 알파벳만 바꿀 수 있음, words에 있는 단어로만 변환될 수 있음
    if target not in words:
        return 0
    
    stack = deque([(begin, 0)])
    visited = [False] * len(words)
    
    while stack:
        w, cnt = stack.popleft()
        if w == target:
            return cnt
        
        for i,k in enumerate(words):
            if not visited[i] and w != k:
                temp = 0
                for a,b in zip(k,w):
                    if a == b:
                        temp += 1
                
                if temp == len(k) - 1:
                    stack.append((k, cnt+1))
                    visited[i] = True
    return 0
                        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#     #begin에서 target으로 변환하는 가장 짧은 변환 과정 찾기, 한 번에 한 개의 알파벳만 바꿀 수 있음 & words에 있는 단어로만 변환할 수 있음
#     #최소 몇단계를 거쳐서 단어를 변환할 수 있는가
#     stack = deque([(0, begin)]) #stack에서 시작
#     visited = [False for _ in range(len(words))]
    
#     while stack:
#         cnt, current = stack.popleft()
#         if current == target:
#             return cnt
        
#         for i, word in enumerate(words):
#             if not visited[i]:
#                 correct = 0
#                 for a, b in zip(word, current):
#                     if a == b:
#                         correct += 1
#                 if correct == len(target)-1:
#                     stack.append((cnt+1, word))
#                     visited[i] = True
#     return 0