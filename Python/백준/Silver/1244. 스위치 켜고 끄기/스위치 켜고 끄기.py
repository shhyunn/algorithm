import sys
input =sys.stdin.readline

N = int(input().strip())
switch = list(map(int, input().strip().split(" ")))

student_num = int(input().strip())
students = []
for _ in range(student_num):
    gender, num = map(int, input().strip().split(" "))
    students.append((gender, num))


for gender, num in students:
    if gender == 1: #남학생인 경우
        for i, s in enumerate(switch):
            if (i+1) % num == 0:
                switch[i] = (s + 1) % 2
    else:
        start = num-1
        end = num-1
        while True:
            start -= 1
            end += 1
            if start >= 0 and end < N and switch[start] == switch[end]:
                continue
            else:
                start += 1
                end -= 1
                break
        for i in range(start, end+1):
            switch[i] = (switch[i]+1) % 2

for i in range(0, len(switch), 20):
    print(" ".join(map(str, switch[i:i+20])))