#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <array>
#include <queue>

using namespace std;
int N = 0;
long long w[10][10];
queue<long long> answer;
int start = 0;


long long dfs(int s, int* v){
        queue<long long> q;
        int vis[10];
        //int* vis = new int(N);
        fill(vis,vis+10,0);
        copy(v,v+10,vis);
        vis[s]=1;
        long long res=0;
        int fin=0;
        for(int u=0;u<N;u++){
                if(u==s)
                        continue;
                for(int i=0;i<N;i++){
                        if(vis[i]==0){
                                fin=1;
                                break;
                        }
                }
                if(fin==0){
                        if(w[s][start]!=0)
                                return w[s][start];
                        else{
                                return 0;
                        }
                }
                if(w[s][u]!=0 && vis[u]==0){
                        res = dfs(u,vis);
                        if(res==0){
                                continue;
                        }
                        else{
                                q.push(w[s][u]+res);
                        }
                }else if(w[s][u]!=0 && vis[u]==1){
                        continue;
                }else{
                        continue;
                }
        }

        long long min = 10000000;
        while(true){
                if(q.empty()==true)
                        break;
                if(min>q.front())
                        min=q.front();
                q.pop();
        }
        if(min==10000000)
                return 0;
        else
                return min;
}

int main(){

        cin >> N;
        //int* vis = new int(N);
        int vis[10];
        fill(vis,vis+10,0);
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                        w[i][j] = 0;
                }
        }


        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        cin >> w[i][j];
                }
        }

        for(int i=0;i<N;i++){
                fill(vis,vis+N,0);
                start=i;
                vis[start]=1;
                long long res = dfs(i,vis);
                if(res!=0){
                        answer.push(res);
                }
        }
        long long least=10000000;
        while(true){
                if(answer.empty()==true)
                        break;
                if(least > answer.front()){
                        least = answer.front();
                }
                answer.pop();
        }
        cout << least << endl;
        return 0;
}
