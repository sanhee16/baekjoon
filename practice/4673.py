max = 10000
#https://www.acmicpc.net/problem/4673


def d(n):
    global selfNumber
    number = n + int(n/1000)%10 +int(n/100)%10+int(n/10)%10+int(n/1)%10
    if(number > max):
        return
    else :
        try :
            selfNumber.index(number)
        except ValueError :
            return

        selfNumber.remove(number)
        return

selfNumber = [i+1 for i in range(max)]
for i in range(max):
    d(i+1)
for i in range(len(selfNumber)):
    print(selfNumber[i])
