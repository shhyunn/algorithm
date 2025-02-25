def solution():
    result = []
    count = 0
    lt, lp = len(T), len(P)
    pi = [0] * lp

    j = 0
    for i in range(1, lp):
        while j > 0 and P[i] != P[j]:
            j = pi[j - 1]

        if P[i] == P[j]:
            j += 1
            pi[i] = j
 
    j = 0
    for i in range(lt):
        while j > 0 and T[i] != P[j]:
            j = pi[j - 1]

        if T[i] == P[j]:
            if j == lp - 1:
                result.append(i - lp + 2)
                count += 1
                j = pi[j]
            else:
                j += 1

    print(count)
    for element in result:
        print(element)


T = input()
P = input()
solution()