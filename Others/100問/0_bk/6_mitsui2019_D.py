## 入力
N = int(input()) 
S = input() 

## 文字列を2次元配列に
LARGE = 999999
ls = [[LARGE]*N for _ in range(10)]
for i,_s in enumerate(S):
    ls[int(_s)][i] = i

## 
ans = 0

for i in range(10):
    # 0桁目の最小INDEX
    if min(ls[i])==LARGE:
        continue
    else:
        idx0 = min(ls[i])
        
    for j in range(10):
        # 1桁目の最小INDEX
        if idx0+1 >=N:
            continue
        elif min(ls[j][idx0+1:])==LARGE:
            continue
        else:
            idx1 = min(ls[j][idx0+1:])
            
        for k in range(10):
            # 2桁目の最小INDEX
            if idx1+1>=N:
                continue
            elif min(ls[k][idx1+1:])==LARGE:
                continue
            else:
                ans += 1
print(ans)
                

    