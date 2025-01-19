# abc387 C - Snake Numbers
import sys
sys.setrecursionlimit(5*10**5)
readline = sys.stdin.readline
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import gcd, lcm
from itertools import permutations

L,R = list(map(int,readline().split()))
memo = [0,0,0]
for i in range(1,18):
    now = 0
    for j in range(1,10):
        now += j**i
    memo.append(now)
# print(memo)

for i in range(len(memo)-1):
    memo[i+1]+= memo[i]


# 8562 -> 
# 856{0~1}
# 85{0~5}{0~7}
# 8{0~4}{0~7}{0~7}
# {1~7}{0~6}.. sig({1~7}**3)

# 210
# 
# 99
# print(memo)
def func(N):
    Ns = str(N)
    cnt = memo[len(Ns)]
    # print(f"digit 0:{cnt}")
    # 1桁目未固定 
    for i in range(1,int(Ns[0])):
        cnt += i**(len(Ns)-1)
    # print(f"digit 1:{cnt}")
    # 1桁目以降
    for i in range(len(Ns)):
        # 判定ロジック breakすればよい。
        if (i>0 and Ns[0]<=Ns[i]):
            break
        # 
        if (i+1==len(Ns)):
            cnt += 1
        else:
            cnt += int(Ns[i+1])*(int(Ns[0])**(len(Ns)-2-i))
        # print(f"digit 2:{cnt} {i}")

    return  cnt


print(func(R)-func(L-1))