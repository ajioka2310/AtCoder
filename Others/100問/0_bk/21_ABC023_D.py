N = int(input()) 
## 複数行の整数列を受け取る場合
A = [list(map(int, input().split())) for _ in range(N)]
max_s = 0
for a in A:
    max_s = max(max_s,a[1])
## binary_searchで候補の高さを決める。
left = 0
right = 10 ** 14
mid = (right+left)//2
## ある高さHを設定した場合、それまでに風船を割り切れるか判定する

def check(mid):
    ls_second = [0 for _ in range(N)]
    for i,a in enumerate(A):
        h,s = a
        if mid < h:
            return False
        ls_second[i] = (mid-h)//s
    ls_second = sorted(ls_second)
    for i,target in enumerate(ls_second):
        if target<i:
            return False
        else:
            pass
    return True

while 1==1:
    # print(left,right,mid)
    if right-left <= 1:    
        break
    mid = (left+right)//2
    flg = check(mid)
    if flg:
        # 探索範囲を左にずらし、右端を絞る
        right = mid
    else:
        # 探索範囲を右にずらし、左端を絞る
        left = mid
        
print(right)
    
        

        

    


