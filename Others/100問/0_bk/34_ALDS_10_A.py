N = int(input())
ls = [1 for _ in range(45)]
for i in range(2,45):
    ls[i] = ls[i-2] + ls[i-1]

print(ls[N])