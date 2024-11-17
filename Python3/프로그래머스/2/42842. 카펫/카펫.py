def solution(brown, yellow):
    for i in range(1, yellow+1):
        if yellow % i == 0:
            j = yellow // i
            if i >= j and yellow + brown == (i+2) * (j+2):
                return [i+2, j+2]