import bisect

N = int(input()) 
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))
C = sorted(list(map(int, input().split())))

# B->Cの組み合わせ数を数える
ls_BC = [0]*N
for i,b in enumerate(B):
    result = bisect.bisect_right(C,b)
    ls_BC[i] = N - result

# A -> B -> C の組み合わせを数える
## A -> Bが成り立つ範囲を調べる
ls_BA = [0]*N
for i,b in enumerate(B):
    result = bisect.bisect_left(A,b)
    ls_BA[i] = result

ans = 0
for a,c in zip(ls_BA,ls_BC):
    ans += a*c

print(ans)