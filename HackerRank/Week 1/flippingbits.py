def flip(n):
    return (2**32-1) - n

a=int(input())
for i in range(a):
    n=int(input())
    print(flip(n))

# if we see bit conversion can be done using 2^32-1 -n simply we will get the solution 