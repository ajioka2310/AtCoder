# abc389 C - Snake Queue
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm
from itertools import permutations

# a = list(map(int,readline().split()))
# ab = [list(map(int,readline().split())) for _ in range()]
# S = readline().strip()
# b = [readline().strip() for _ in range()]

Q = int(readline())

cnt = 0
sub = 0
ls = [0]
for _ in range(Q):
    q = readline()
    if q[0]=='1':
        l = int(q.split()[-1])
        ls.append(ls[-1]+l)
    elif q[0]=='2':
        cnt += 1
    else:
        k = int(q.split()[-1])
        print(ls[k-1+cnt]-ls[cnt])


