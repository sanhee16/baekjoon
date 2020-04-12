#https://www.acmicpc.net/workbook/view/1299

"""
https://www.acmicpc.net/problem/9465

"""
import numpy as np
sticker = np.array([[50,10,100,20,40],
                    [30,50,70,10,60]])

sticker2 = np.array([[10,30,10,50,100,20,40],
                     [20,40,30,50,60,20,80]])


def biggest_score(n,arr) :
    c = np.zeros((4, n+1), int)
    for i in range(0,n+1) :
        c[0][i] = 0
    for i in range(0,4):
        c[i][0] = 0

    for i in range(0,n) :
        ii = i + 1
        for p in range(1,4):
            if (p==3) :
                position = -1
                qList = [1,2,3]
            elif (p==2) :
                position = 1
                qList = [1,3]
            elif (p==1) :
                position = 0
                qList = [2,3]

            max = 0
            for q in qList:
                if (position == -1):
                    add_score = 0
                else :
                    add_score =arr[position][i]

                if (max < c[q][ii-1] + add_score) :
                    max = c[q][ii-1] + add_score

            c[p][ii] = max


    return np.max(c)


print(biggest_score(5,sticker))
print(biggest_score(7,sticker2))




