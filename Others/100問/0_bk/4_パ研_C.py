N,M = map(int, input().split())
## 複数行の整数列を受け取る場合
A = [list(map(int, input().split())) for _ in range(N)]

ans = 0
for a in range(M):
    for b in range(a+1,M):
        score = 0
        for i in range(N):
            score += max(A[i][a],A[i][b])
        ans = max(score,ans)
print(ans)
            
            
        