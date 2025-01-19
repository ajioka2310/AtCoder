# abc389 D - Squares in Circle
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm, sqrt
from itertools import permutations

R = int(readline())

ans = 0

# i == 0
for i in range(R+1):
    ok = -1
    ng = 10**6
    while ng-ok>1:
        mid = (ok+ng)//2
        r = sqrt((0.5+i)**2+(0.5+mid)**2)
        if (r<=R):
            ok = mid
        else:
            ng = mid
    if ok == -1:
        pass
    else:
        ans += 2*ok+1 if i==0 else 2*2*ok+2
    # print(i,ok)
print(ans)