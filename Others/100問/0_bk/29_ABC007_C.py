import sys
from collections import deque
input = sys.stdin.readline

class Node:
    def __init__(self):
        self.parent = [0,0]
        self.gen = -1
        

R,C = map(int, input().split())
st = list(map(int, input().split()))
ed = list(map(int, input().split()))

MAP = [[True for _ in range(C+2)]]
for _ in range(R):
    ls = [True for _ in range(C+2)]
    inp = list(input()[:-1])
    for i,now in enumerate(inp):
        if now != "#":
            ls[i+1] = False
    MAP.append(ls)
MAP.append([True for _ in range(C+2)])

graph = [[Node() for _ in range(C+2)] for _ in range(R+2)]
        
Q = deque([st])
MAP[st[0]][st[1]] = False
while 1==1:
    if len(Q)==0:
        break
    
    now = Q.popleft()
    node = graph[now[0]][now[1]]
    node.gen = graph[node.parent[0]][node.parent[1]].gen + 1
    
    for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        if not MAP[now[0]+dx][now[1]+dy]:
            Q.append([now[0]+dx,now[1]+dy])
            graph[now[0]+dx][now[1]+dy].parent = [now[0],now[1]]
            MAP[now[0]+dx][now[1]+dy] = True

print(graph[ed[0]][ed[1]].gen)
    
        



