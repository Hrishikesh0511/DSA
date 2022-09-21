(start,end)=map(int,input().split())
def prime(num):
    for i in range(2,num//2):
        if(num%i==0):
            return False
        else:
            continue
    return True
for i in range(start,end):
    if(prime(i)):
        print(i)