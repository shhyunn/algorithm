def solution(rows, columns, queries):
    #행렬에서 직사각형을 여러 번 선택해 시계방향으로 회전..오른쪽으로 이동, 중앙은 회전 안함, 각 회전들을 적용하고 그 회전에 의해 위치가 바뀐 숫자들을 배열에 담아.. 회전 당 최솟값을 순서대로
    answer = []
    maps = [[i * columns + j + 1 for j in range(columns)] for i in range(rows)]
    for q in queries:
        x1, y1, x2, y2 = q
        
        #x1에서 x2까지 y1 고정일 때 이동, 다만 마지막인 건
        prev = maps[x1-1][y1-1]
        min_value = prev
        
        #y1부터 y2까지 x2 고정
        for i in range(y1, y2): #두번째 요소부터 마지막 요소까지
            maps[x1-1][i], prev = prev, maps[x1-1][i]
            min_value = min(min_value, prev)
        
        for i in range(x1, x2): #두번째 요소부터 마지막 요소까지
            maps[i][y2-1], prev = prev, maps[i][y2-1]
            min_value = min(min_value, prev)
        
        #y2부터 y1까지 x1 고정
        for i in range(y2-2, y1-2, -1): #두번째 요소부터 마지막 요소까지
            maps[x2-1][i], prev = prev, maps[x2-1][i]
            min_value = min(min_value, prev)
            
        #x2부터 x1까지 y2 고정
        for i in range(x2-2, x1-2, -1): #두번째 요소부터 마지막 요소까지
            maps[i][y1-1], prev = prev, maps[i][y1-1]
            min_value = min(min_value, prev)
            
        answer.append(min_value)
               
    return answer