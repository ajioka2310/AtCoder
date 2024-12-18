# 深さ優先探索（行きがけ）
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7) #再帰関数の呼び出し制限

M = int(input())
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

A_fix = [[0 for _ in range(M+2)]]
for ls in A:
    A_fix.append([0]+ls+[0])
A_fix.append([0 for _ in range(M+2)])

seen = [[True for _ in range(M+2)] for _ in range(N+2)]

for i in range(1,N+1):
    for j in range(1,M+1):
        if A_fix[i][j]==1:
            seen[i][j] = False
ans = 0       
def dfs(i,j,depth,seen):
    global ans
    seen[i][j] = True
    for next_i,next_j in [(i,j-1),(i,j+1),(i-1,j),(i+1,j)]:
        if i==next_i or j==next_j:
            if seen[next_i][next_j]:
                continue
            else:
                dfs(next_i,next_j,depth+1,seen)
    ans = max(ans,depth)

ans = 0
for i in range(1,N+1):
    for j in range(1,M+1):
        if not seen[i][j]:
            tmp_seen = [i[:] for i in seen]
            dfs(i,j,1,tmp_seen)
            
print(ans)
                
