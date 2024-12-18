# メモリエラーになる。
import sys
from collections import deque
input = sys.stdin.readline

R,C,N = map(int, input().split())
target = [[] for _ in range(N+1)]

MAP = [[True for _ in range(C+2)]]
for row in range(1,R+1):
    ls = [True for _ in range(C+2)]
    inp = list(input()[:-1])
    for i,now in enumerate(inp):
        if now == ".":
            ls[i+1] = False
        elif now == "X":
            pass
        else:
            if now=="S":
                now = 0
            ls[i+1] = False
            target[int(now)] = [row,i+1]
    MAP.append(ls)
MAP.append([True for _ in range(C+2)])


ans = 0
for i in range(1,N+1):
    st = target[i-1]
    ed = target[i]
    graph = [[[0,0,-1] for _ in range(C+2)] for _ in range(R+2)]
    seen = [_MAP[:] for _MAP in MAP]
    Q = deque([st])
    seen[st[0]][st[1]] = True # ?
    # print(i,st,ed)
    # print(seen)
    while 1==1:
        now = Q.popleft()
        parent_x,parent_y = graph[now[0]][now[1]][0:2]
        graph[now[0]][now[1]][2] = \
        graph[parent_x][parent_y][2] + 1
        
        for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            if not seen[now[0]+dx][now[1]+dy]:
                Q.append([now[0]+dx,now[1]+dy])
                # 親ノードのメモ
                graph[now[0]+dx][now[1]+dy][0] = now[0]
                graph[now[0]+dx][now[1]+dy][1] = now[1]
                seen[now[0]+dx][now[1]+dy] = True
        if all([x==y for x,y in zip(ed,now)]):
            ans += graph[now[0]][now[1]][2]
            break
    
print(ans)
        
    
    
    