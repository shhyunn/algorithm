def solution(brown, yellow):
    #카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했으나, 전체 카펫의 크기는 기억하지 못함
    #카펫의 가로, 세로 크기를 순서대로 배열에 담기
    
    for i in range(1, yellow+1):
        if yellow % i != 0:
            continue
            
        j = yellow // i
        if (i+2) * (j+2) - i*j == brown:
            return [j+2, i+2]
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    # for i in range(1, yellow+1):
    #     if yellow % i == 0:
    #         j = yellow // i
    #         if i >= j and yellow + brown == (i+2) * (j+2):
    #             return [i+2, j+2]