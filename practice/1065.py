
import sys

max = 1000
input = sys.stdin.readline()
N = int(input)
#print(N)
num = 0

for i in range(N):
    X = i+1
    num1 = int(X/1)%10
    num2 = int(X/10)%10
    num3 = int(X/100)%10
    num4 = int(X/1000)%10

    if(num4 != 0):
        if((num4-num3) == (num3-num2) == (num2-num1) or (num3-num4) == (num2-num3) == (num1-num2)):
            num += 1
    else :
        if(num3!=0):
            if((num3-num2) == (num2-num1) or (num2-num3) == (num1-num2)):
                num += 1
        else:
            if(num2!=0):
                num += 1
            else:
                if(num1!=0):
                    num += 1



print(num)
