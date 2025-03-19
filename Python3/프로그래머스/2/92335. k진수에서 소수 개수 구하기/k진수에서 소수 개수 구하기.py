def convert(n,k):
    res = ""
    while n != 0:
        res = str(n % k) + res
        n = n // k
    
    return res

def is_prime(n):
    if n == 1:
        return 0
    
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return 0
    
    return 1


def solution(n, k):
    str = convert(n, k) #k진수로 변환
    
    lst = list(str.split("0"))
    ans = 0
    
    for l in lst:
        if len(l) > 0:
            ans += is_prime(int(l))
        
    return ans
