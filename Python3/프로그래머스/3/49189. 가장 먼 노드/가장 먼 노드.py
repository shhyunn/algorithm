from collections import defaultdict, deque

def solution(n, edge):
    # 그래프 생성
    graph = defaultdict(list)
    for a, b in edge:
        graph[a].append(b)
        graph[b].append(a)  # 양방향 연결

    # BFS 초기 설정
    distances = [-1] * (n + 1)  # 각 노드의 거리 (-1은 방문하지 않은 상태)
    distances[1] = 0            # 시작 노드(1번 노드)의 거리는 0
    queue = deque([1])          # BFS를 위한 큐

    # BFS로 최단 거리 계산
    while queue:
        current = queue.popleft()
        for neighbor in graph[current]:
            if distances[neighbor] == -1:  # 방문하지 않은 노드만 처리
                distances[neighbor] = distances[current] + 1
                queue.append(neighbor)

    # 최대 거리 계산 및 해당 거리의 노드 개수 반환
    max_distance = max(distances)
    return distances.count(max_distance)