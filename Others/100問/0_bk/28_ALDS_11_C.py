import sys
from collections import deque
input = sys.stdin.readline

class Node:
    def __init__(self):
        self.parent = 0
        self.children = deque([])
        self.gen = -1

N = int(input())
graph = [Node() for _ in range(N+1)]

for _ in range(N):
    A = list(map(int, input().split()))
    for v in A[2:]:
        graph[A[0]].children.append(v)

seen = [False for _ in range(N+1)]
score = [-1 for _ in range(N+1)]
Q = deque([1])
seen[1] = True

while 1==1:
    
    if len(Q)==0:
        break
    # 一番古いノードを取得
    now = Q.popleft()
    node = graph[now]
    # 世代ノードを更新
    node.gen = graph[node.parent].gen + 1
    score[now] = node.gen
    # seen[now] = True
    # print("---info---")
    # print(node.children)
    # print(node.parent)
    # print(node.gen)
    # print("----------\n")
    for i in node.children:
        if not seen[i]:
            Q.append(i)
            graph[i].parent = now
            seen[i] = True
        
for i in range(1,N+1):
    print(f"{i} {score[i]}")