# abc389 B - tcaF
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm
from itertools import permutations

X = int(readline())

now = 2
while True:
    X /= now
    if X==1:
        break
    now += 1
print(now)

