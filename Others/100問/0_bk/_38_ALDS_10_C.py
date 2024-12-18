# 時間が間に合わないCだと間に合いそう
N = int(input())
ans = []
for i in range(N):
    A = list(input())
    B = list(input())
    dp = [[0 for _ in range(len(A)+1)] for _ in range(len(B)+1)]
    for i in range(1,len(B)+1):
        for j in range(1,len(A)+1):
            if B[i-1]==A[j-1]:
                dp[i][j] = max(
                    dp[i-1][j-1]+1,
                    dp[i][j-1],
                    dp[i-1][j]
                )
            else:
                dp[i][j] = max(
                    dp[i][j-1],
                    dp[i-1][j]
                )
    ans.append(dp[-1][-1])  
for i in ans:
    print(i)           
                