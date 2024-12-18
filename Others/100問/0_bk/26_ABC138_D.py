# 深さ優先探索（行きがけ）
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7) #再帰関数の呼び出し制限

# グラフの作成(無向グラフでは#を消す)
N,Q = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for _ in range(N-1):
    a,b = [int(x) for x in input().split()]
    graph[a].append(b)
    graph[b].append(a) # 無向グラフ
graph = [sorted(ls) for ls in graph]

points = [0] * (N+1)
for _ in range(Q):
    p,x = [int(x) for x in input().split()]
    points[p] += x


# 深さ優先探索
def dfs(node,seen,points):
    # print(node, seen)
    seen[node] = True
    for next_node in graph[node]:
        if seen[next_node]:
            continue
        else:
            points[next_node] = points[node] + points[next_node]
            dfs(next_node,seen,points)
    return points

seen = [False for _ in range(N+1)]
ans = dfs(1, seen, points)
# print(graph)
print(*ans[1:])

"""
4 3
1 2
1 3
2 4
"""