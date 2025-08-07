def Permutetwoarrays(k,A,B):
    A.sort()
    B.sort(reverse=True)
    for i in range(len(A)):
        if A[i]+B[i]<k:
            return "NO"
    return "YES"
q=int(input())
for i in range(q):
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    C=Permutetwoarrays(k,A,B)
    print(C)