"""
https://www.acmicpc.net/problem/2606


"""
import numpy as np
n = 7
graph = np.zeros((8,8),int)
List1 = [1,2,1,5,5,4]
List2 = [2,3,5,2,6,7]
for i in range(len(List1)):
        graph[List1[i]][List2[i]] = graph[List2[i]][List1[i]] = 1

print(graph)
count = 0

def Dfs(s):
    visited = [0 for i in range(0,n+1)]
    """
    for u in range(1,n+1):
        if(visited[u]==0):
            aDfs(u,visited)
    """
    aDfs(s,visited)
    return

def aDfs(u,visited):
    visited[u] = 1
    global count
    for v in range(1,n+1):
        if(graph[u][v]==1 and visited[v]==0):
            aDfs(v,visited)
            count = count + 1

    return
#Dfs()

def virus(s):
    Dfs(s)
    return

virus(1)
print(count)









