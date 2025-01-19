W,H,x,y = map(int, input().split())

flg = 0
if (W==x*2 and H==y*2):
    flg = 1
print("{} {}".format(W*H/2,flg))
