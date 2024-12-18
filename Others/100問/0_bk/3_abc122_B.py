S = input() 
N = len(S)
#
ls = []
for i in range(N+1):
    for j in range(1,N-i+1):
        ls.append(S[i:][:j])
#
def check(s):
    for _s in s:
        if _s in ["A","C","G","T"]:
            pass
        else:
            return False
    return True

ans = 0
for s in ls:
    n = len(s)
    if check(s) and n>ans:
        ans = len(s)
            
print(ans)
    