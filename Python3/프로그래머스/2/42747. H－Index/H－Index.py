def solution(citations):
    citations.sort(reverse=True)  # 내림차순 정렬
    h = 0

    for i, c in enumerate(citations):
        if i + 1 <= c:  # i+1번째 논문이 i+1번 이상 인용되었다면
            h = i + 1
        else:
            break

    return h