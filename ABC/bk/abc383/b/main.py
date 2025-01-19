# abc383 B - Humidifier 2
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm
from itertools import product,permutations

# n = int(readline())
H,W,D = list(map(int,readline().split()))
# ab = [list(map(int,readline().split())) for _ in range()]
# S = readline().strip()
S = [readline().strip() for _ in range(H)]
ans = 0
for dh1, dw1, dh2, dw2 in product(range(H), range(W),range(H), range(W)):
    now = 0
    if (S[dh1][dw1]=='.' and S[dh2][dw2]=='.'):
        for h,w in product(range(H),range(W)):
            if S[h][w]=='.' and (abs(dh1-h)+abs(dw1-w)<=D or abs(dh2-h)+abs(dw2-w)<=D):
                now+=1
    ans = max(ans,now)
print(ans)



