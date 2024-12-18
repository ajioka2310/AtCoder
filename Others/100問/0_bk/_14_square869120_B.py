N, K = map(int, input().split())
A = list(map(int, input().split()))

def popcount(x):
    res = 0
    while x > 0:
        res += x & 1
        x >>= 1
    return res

ans = float("inf")
for s in range(1<<N):
    # bitが立っている数がK以上の場合は処理を打ち切る
    if popcount(s) < K:
        continue
    
    now = 0 # 最大高さ
    cnt = 0 # 金額

    for i, a in enumerate(A):
        # bitが立っている場合    
        if (s>>i) & 1:
            # 対象のビルのが最大高さになる場合は処理せず、最大値のみ更新
            if a > now:
                now = a
            # ビルの高さを更新し、お金を払う
            else:
                now += 1
                cnt += now - a
        # bitが立っていない場合処理をせず、最大値のみ更新
        else:
            now = max(now, a)
    
    ans = min(ans, cnt)

print(ans)