## 整数を受け取る場合
A,B,C,X,Y = map(int, input().split())

#case 1
ans1 = A*X+B*Y
# case 2
ans2 = 2*max(X,Y)*C

# case 3
if X>Y:
    ans3 = 2*Y*C + (X-Y)*A
else:
    ans3 = 2*X*C + (Y-X)*B
    
print(min(ans1,ans2,ans3))