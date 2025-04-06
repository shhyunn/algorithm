#N극 0 S극 1
arr = []
for _ in range(4):
	tmp = list(map(int, list(input())))
	arr.append(tmp)

def cycle(k,d):
	global arr
	if d == 1:
		arr[k] = [arr[k][-1]] + arr[k][:7]

	elif d == -1:
		arr[k] = arr[k][1:] + [arr[k][0]]


def rotate(k, d, flag): #몇번 톱니바뀌, 어떤 방향으로 회전할지, -1: left, 0: 양쪽, 1: right
	global arr
	#양옆 회전을 시키면 됨.

	if k == 0: #1번 톱니바퀴 회전일 경우, 오른쪽 영향만 고려
		if flag != -1 and arr[k][2] != arr[k+1][6]: #극이 다를 경우
			rotate(k+1, -d, 1) #오른쪽 회전
		cycle(k, d)

	if k == 3:
		if flag != 1 and arr[k][6] != arr[k-1][2]:
			rotate(k-1, -d, -1) #왼쪽으로 영향 전파
		cycle(k, d)

	if 0 < k < 3:
		if flag != -1 and arr[k][2] != arr[k+1][6]: #왼쪽이 아닐경우, 오른쪽 영향 전파 경우
			rotate(k+1, -d, 1)
		if flag != 1 and arr[k][6] != arr[k-1][2]: #오른쪽이 아닐 경
			rotate(k-1, -d, -1)
		cycle(k,d)



N = int(input())

for _ in range(N):
	k, d = map(int, input().split())

	rotate(k-1, d, 0) #양 방향 모두 영향 전파

res = 0

for i in range(4):
	if arr[i][0] == 1:
		res += (2 ** i)

print(res)