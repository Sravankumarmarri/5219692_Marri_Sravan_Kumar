n=int(input())
a=list(map(int,input().split()))
count={}
for i in a:
    if i in count:
        count[i]+=1
    else:
        count[i]=1
for i in a:
    if count[i]==1:
        print(i)

# i have used simple logic i have taken each number count and i have printed the number whose count is 1