N,W = map(int, input().split())
dp = [[0 for _ in range(W+1)] for _ in range(N+1)]
items = [list(map(int, input().split())) for _ in range(N)] # v,w

for i in range(1,N+1):
    v,w = items[i-1]
    for j in range(W+1):
        if w>j:
            dp[i][j] = dp[i-1][j]
        else:
            ans1 = dp[i][j-w]+v
            ans2 = dp[i-1][j]
            dp[i][j] = max(ans1,ans2)

print(dp[-1][W])