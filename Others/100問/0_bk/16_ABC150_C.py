import itertools
from math import sqrt

N = int(input()) 
P = [i-1 for i in list(map(int, input().split()))]
Q = [i-1 for i in list(map(int, input().split()))]

for count_P, v in enumerate(itertools.permutations(range(N),N)):
    if all(x==y for x,y in zip(P,v)):
        break
    
for count_Q, v in enumerate(itertools.permutations(range(N),N)):
    if all(x==y for x,y in zip(Q,v)):
        break

print(abs(count_P-count_Q))