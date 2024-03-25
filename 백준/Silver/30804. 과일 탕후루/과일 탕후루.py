import sys
input = sys.stdin.readline

N = int(input())
#과일을 두 종류 이하로 사용, 앞쪽과 뒤쪽에서 과일을 빼서 두 종류 이하의 과일만 남기기
#앞에서 a개, 뒤에서 b개의 과일 빼기
#과일의 개수가 가장 많은 탕후루의 과일 개수
#두 포인터???
fruits = list(map(int, input().split()))

two_lst = set([])
prev = ""
prev_cnt = 0
max_val = -1
temp = 0

for k in fruits:
    if prev == k:
        prev_cnt += 1
        temp += 1

    else: #prev랑 다르다면
        if k in two_lst:
            prev = k
            prev_cnt = 1
            temp += 1

        else: #없다면
            if len(two_lst) < 2:
                two_lst.add(k)
                prev = k
                prev_cnt = 1
                temp += 1

            else: #없는데 이미 꽉참
                max_val = max(max_val, temp)
                temp = prev_cnt + 1

                two_lst = set([k])
                if prev != "":
                    two_lst.add(prev)
                prev = k
                prev_cnt = 1

max_val = max(max_val, temp)
print(max_val)