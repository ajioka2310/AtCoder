# abc387 B - 9x9 Sum
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm
from itertools import permutations

n = int(readline())
# a = list(map(int,readline().split()))
# ab = [list(map(int,readline().split())) for _ in range()]
# S = readline().strip()
# b = [readline().strip() for _ in range()]

ans = 0
for i in range(1,10):
    for j in range(1,10):
        if i*j!=n:
            ans += i*j
print(ans)