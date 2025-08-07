s=input()
alphabets="abcdefghijklmnopqrstuvwxyz"
temp=True
s=s.lower()
for i in alphabets:
    if i in s:
        temp=True
    else:
        temp=False
        break
if temp==True:
    print("pangram")
else:
    print("not pangram")