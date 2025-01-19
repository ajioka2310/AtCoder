N = int(input())
xy = [map(int, input().split()) for _ in range(N)]
x, y = [list(i) for i in zip(*xy)]

nowx,nowy = 0,0
ans = 0
for _x,_y in zip(x,y):
  ans += ((_x-nowx)**2+(_y-nowy)**2)**0.5
  nowx = _x
  nowy = _y

ans += ((_x)**2+(_y)**2)**0.5
print(ans)  
