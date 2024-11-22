import sys
input = sys.stdin.readline

strr = input().strip()

res = 0

stack = []
dic = {")": "(", "]": "["}
dic2 = {")" : 2, "]": 3}

correct = 1
for s in strr:
    if not stack:
        stack.append(s)
        continue

    if s == "(" or s == "[":
        stack.append(s)
        continue
    else: #)]일 경우
        if stack[-1] == dic[s]: #스택의 가장 마지막과 동일할 경우
            stack.pop()
            stack.append(str(dic2[s])) #해당하는 숫자 집어넣기
        else: #동일하지 않을 때..
            temp = 0
            success = 0
            while stack:
                last = stack[-1] #스택의 가장 마지막 요소
                if last.isdigit(): #숫자일 경우에는
                    temp += int(last) #temp에 저장
                    stack.pop() #숫자 삭제

                elif last == dic[s]: #괄호가 동일할 경우에는
                    stack.pop() #여는 괄호 삭제
                    stack.append(str(temp * dic2[s])) #곱하기해서 스택에 저장
                    success = 1
                    break

                else: #괄호가 불일치할 경우
                    res = 0
                    correct = 0 #이상한 문장임
                    break
            if success == 0:
                correct = 0
                break

    if correct == 0:
        break

if correct == 1:
    res = 0
    for s in stack:
        if s.isdigit():
            res += int(s)
        else:
            res = 0
            break
    print(res)

else:
    print(0)