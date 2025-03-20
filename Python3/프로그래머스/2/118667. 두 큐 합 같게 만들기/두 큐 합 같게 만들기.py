from collections import deque

def solution(queue1, queue2):
    #각 큐의 원소 합이 같도록, 이때 필요한 작업의 최소 횟수?? pop + insert 1회 수행
    #pop을 하면 배열의 첫번째 원소 추출, insert 하면 배열 끝에 원소 추가
    answer = 0
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    full_sum = (sum(queue1) + sum(queue2))
    if full_sum % 2 == 1:
        return -1
    half_sum = full_sum // 2
    curr_sum = sum(queue1)
    
    while answer <= 1200000:
        if curr_sum == half_sum:
            return answer
        
        elif curr_sum > half_sum:
            a = queue1.popleft()
            queue2.append(a)
            curr_sum -= a
            
        else:
            a = queue2.popleft()
            queue1.append(a)
            curr_sum += a
        answer += 1

    return -1