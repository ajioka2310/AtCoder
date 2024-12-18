# 深さ優先探索（行きがけ）
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7) #再帰関数の呼び出し制限

# グラフの作成(無向グラフでは#を消す)
N = int(input())
graph = [[] for _ in range(N + 1)]
for _ in range(N):
    v = [int(x) for x in input().split()] # uは頂点番号、kは隣接頂点の個数
    for i in v[2:]:
        graph[v[0]].append(i)
        # graph[i].append(v[0]) # 無向グラフ
for i in range(N+1):
    graph[i] = sorted(graph[i])
time = 0
first_times = [-1] * (N + 1) # 到着時刻
last_times = [-1] * (N + 1)

# 深さ優先探索
def dfs(node,seen):
    # print(node, seen)
    global time
    time += 1
    seen[node] = True
    first_times[node] = time
    for next_node in graph[node]:
        if seen[next_node]:
            continue
        else:
            dfs(next_node,seen)
    time += 1
    last_times[node] = time
    return first_times,last_times


seen = [False for _ in range(N+1)]
for i in range(1,N+1):
    if not seen[i]:
        first_times, last_times = dfs(i,seen)

    
for i,(first,last) in enumerate(zip(first_times,last_times)):
    if i==0:
        pass
    else:
        print(f"{i} {first} {last}")