
N,M = map(int, input().split())
A = list(map(int, input().split()))

dp = [[10**9 for _ in range(N+1)] for _ in range(M+1)]

for i in range(1,M+1):
    n = A[i-1]
    for j in range(1,N+1):
        # 払い方がない場合
        if n>j:
            dp[i][j] = dp[i-1][j]
        elif n==j:
            dp[i][j] = 1
        else:
            ans1 = dp[i-1][j]
            ans2 = dp[i][j-n] + 1
            dp[i][j] = min(ans1,ans2)
print(dp[-1][N])
