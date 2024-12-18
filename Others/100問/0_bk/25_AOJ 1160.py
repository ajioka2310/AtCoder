# 深さ優先探索（行きがけ）
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7) #再帰関数の呼び出し制限

ls_ans = []
while 1==1:
    w,h = map(int, input().split())
    if w==0 and h==0:
        break
    A = [[0 for _ in range(w+2)]]
    for i in range(h):
        ls = [0]+ [int(i) for i in input().split()] + [0]
        A.append(ls)
    A.append([0 for _ in range(w+2)])

    seen = [[True for _ in range(w+2)] for _ in range(h+2)]
    for i in range(1,h+1):
        for j in range(1,w+1):
            if A[i][j]:
                seen[i][j] = False
                
    def dfs(i,j):
        if not seen[i][j]:
            seen[i][j] = True
        for next_i in [i-1,i,i+1]:
            for next_j in [j-1,j,j+1]:
                if seen[next_i][next_j]:
                    continue
                else:
                    dfs(next_i,next_j)

    ans = 0
    for i in range(1,h+1):
        for j in range(1,w+1):
            if not seen[i][j]:
                dfs(i,j)
                ans += 1
            else:
                pass
    ls_ans.append(ans)
for i in ls_ans:
    print(i)

"""_summary_
24 20
1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 1
1 0 1 1 0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 1
1 0 1 1 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 1 0 0 1
1 0 1 0 1 0 0 0 1 0 0 1 1 1 0 0 0 1 0 0 0 0 0 1
1 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 1 0 1
1 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0 0 1 1 0 0 1 0 1
1 0 1 0 1 1 0 0 1 0 1 0 0 0 0 0 1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1
1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1
1 0 0 0 0 0 1 1 0 1 0 1 0 0 0 0 0 1 0 1 0 0 0 1
1 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 1 0 0 1
1 0 1 0 1 0 0 1 0 0 0 0 1 1 0 1 0 1 0 0 0 0 0 1
1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 1 0 1
1 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 1 0 1 1 0 0 0 1
1 0 0 0 0 0 0 0 1 1 0 1 1 0 1 1 0 0 0 1 0 0 0 1
1 0 0 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1
1 0 0 1 0 0 0 0 0 1 1 1 1 1 0 0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 1 0 1 1 0 0 1
1 0 0 0 0 1 0 0 1 0 0 1 0 1 1 0 1 1 1 0 0 0 0 1
0 0
"""