import sys
input = sys.stdin.readline

# 초기 문자열 입력 및 명령어 개수 입력
strr = input().strip()
N = int(input().strip())

# 초기 문자열을 왼쪽 스택에 모두 넣기 (커서가 문자열 끝에 있다고 가정)
left_stack = list(strr)
right_stack = []

for _ in range(N):
    command = input().strip().split()
    
    if command[0] == "L":  # 커서를 왼쪽으로 이동
        if left_stack:
            right_stack.append(left_stack.pop())
    elif command[0] == "D":  # 커서를 오른쪽으로 이동
        if right_stack:
            left_stack.append(right_stack.pop())
    elif command[0] == "B":  # 커서 왼쪽 문자 삭제
        if left_stack:
            left_stack.pop()
    elif command[0] == "P":  # 커서 왼쪽에 문자 삽입
        left_stack.append(command[1])

# 결과 출력: left_stack + right_stack (오른쪽 스택은 역순으로 출력해야 함)
print("".join(left_stack + right_stack[::-1]))