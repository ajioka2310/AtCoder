import itertools
from math import sqrt
# for v in itertools.permutations(ls,4):
#     print(v)

N = int(input()) 
A = [list(map(int, input().split())) for _ in range(N)]

dic_dist = {}
for i in range(N):
    dic_dist[i] = {}

for a,b in itertools.permutations(range(N),2):
    dic_dist[a][b] = sqrt((A[a][0]-A[b][0])**2+(A[a][1]-A[b][1])**2)

sum_distance = 0
for i, v in enumerate(itertools.permutations(range(N),N)):
    for j in range(1,N):
        sum_distance += dic_dist[v[j-1]][v[j]]
print(sum_distance/(i+1))