import sys
input = sys.stdin.readline

#이야기의 진실을 아는 사람, 모든 파티에 참가해야 함, 과장된 이야기를 할 수 있는 파티 개수의 최댓값
N,M = map(int, input().split())
plist = list(map(int, input().split())) #진실한 이야기를 알고있는 사람
pnum = plist[0] #사람 수
party = [] #party 리스트
person = {key:[] for key in range(1,N+1)}
party_num = [0 for _ in range(M)]
visited = [False for _ in range(N+1)]

for i in range(M):
    temp = list(map(int, input().split()))
    party_num[i] = temp[0]
    party.append(temp[1:]) #해당 party에 대해 참가한 사람 리스트
    for k in temp[1:]: #사람 리스트
         person[k].append(i)

def dfs(k): #dfs할 사람
        for p in person[k]: #그 person이 참가한 party
            party_num[p] -= 1
            for n in party[p]: #party에 참가한 리스트
                # print(p,n)
                if not visited[n]:
                    visited[n] = True
                    dfs(n)

for i in range(1,pnum+1):
    visited[plist[i]] = True
    dfs(plist[i]) #3으로 시작

cnt = 0
for r in party_num:
     if r > 0:
        cnt += 1

print(cnt)