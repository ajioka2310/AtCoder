N = int(input()) 

ans = 0
ls = [3,5,7,11,13]
# case 1
for i in ls:
    for j in ls:
        for k in ls:
            if i*j*k <= N and i<j and j<k:
                ans += 1
# case 2
for i in ls:
    for j in ls:
        if i*i*i*j <= N and i<j and j<k:
            ans += 1
            
        elif i*j*j*j < N and i<j and j<k:
            ans += 1
            
        else:
            pass
                
print(ans)
            