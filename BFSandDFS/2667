
import numpy as np
"""
https://www.acmicpc.net/problem/2667
"""

graph = np.array([[0,1,1,0,1,0,0],
                  [0,1,1,0,1,0,1],
                  [1,1,1,0,1,0,1],
                  [0,0,0,0,1,1,1],
                  [0,1,0,0,0,0,0],
                  [0,1,1,1,1,1,0],
                  [0,1,1,1,0,0,0]])

n = 7

a = 0
num_apart = [0 for i in range(0,n*n)]
id = [-1 for i in range(0,n*n)]

def find_apart():

    vis = np.zeros((n,n),int)
    global a
    for i in range(0,n):
        for j in range(0,n):
            if(vis[i][j]==0):
                search(i,j,vis)
                a = a+1


def search(i,j,vis):
    vis[i][j]=1
    global a

    if(graph[i][j]==0):
        return
    elif(graph[i][j]==1):
        id[a] = a
        num_apart[a] = num_apart[a] + 1
        if(i+1 < n and vis[i+1][j]==0):
            search(i+1,j,vis)
        if(j+1 < n and vis[i][j+1]==0):
            search(i,j+1,vis)
        if(i-1 >-1 and vis[i-1][j]==0):
            search(i-1,j,vis)
        if(j-1 >-1 and vis[i][j-1]==0):
            search(i,j-1,vis)



find_apart()
for i in range(0,n*n):
    if(id[i]!=-1):
        print(num_apart[i])
        print("-----")









