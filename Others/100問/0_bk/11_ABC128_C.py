N, M = map(int, input().split())

## 複数行の整数列を受け取る場合
A = [list(map(int, input().split())) for _ in range(M)]
P = list(map(int, input().split()))

S = [i[1:] for i in A] # スイッチリスト
R = [i[0] for i in A] # Rule

## 点灯判定
ans = 0
# スイッチの１パターンを試す。
for bit in range(1<<N):
    # print(f"bit: {bit}")
    pattern = [0] * N
    for i in range(N):
        if bit & (1<<i):
            pattern[i] = 1
    # パターンでの点灯結果を確認
    conditon = [0] * M
    for i, s in enumerate(S):
        for _s in s:
            if pattern[_s-1] == 1:
                conditon[i] += 1
    conditon = [i%2 for i in conditon]
    # print(f"pattern: {pattern}")
    # print(f"P: {P}")
    # print(f"condition: {conditon}")
    
    if all(x==y for x,y in zip(P,conditon)):
        ans += 1    
# OUTPUT   
print(ans)