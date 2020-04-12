#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <array>
#include <queue>

using namespace std;
int input_arr[102][102];
int g[102][102];
int vis[102][102];

void init(){
        for(int i=0;i<102;i++){
                fill(g[i],g[i]+102,-1);
                fill(vis[i],vis[i]+102,0);
        }
}
int bfs(int i,int j){

        if(g[i][j]!=1){
                vis[i][j]=1;
                return 0;
        }

        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        int u,v;
        while(true){
                if(q.empty()==true)
                        return 1;
                u = q.front().first;
                v = q.front().second;
                q.pop();
                vis[u][v]=1;

                if(g[u][v]!=1){
                        continue;
                }

                if(g[u][v]==1){
                        if(vis[u+1][v]==0){
                                q.push(make_pair(u+1,v));
                                vis[u+1][v]=1;
                        }
                        if(vis[u-1][v]==0){
                                q.push(make_pair(u-1,v));
                                vis[u-1][v]=1;
                        }
                        if(vis[u][v+1]==0){
                                q.push(make_pair(u,v+1));
                                vis[u][v+1]=1;
                        }
                        if(vis[u][v-1]==0){
                                q.push(make_pair(u,v-1));
                                vis[u][v-1]=1;
                        }

                }
        }

}



int main(){

        int N=0;
        cin >> N;
        queue<int> answer;
        for(int i=0;i<102;i++){
                fill(input_arr[i],input_arr[i]+102,-1);
        }

        int h=0;
        for(int i=1;i<N+1;i++){
                for(int j=1;j<N+1;j++){
                        cin >> h;
                        input_arr[i][j] = h;
                }
        }


        int time=0;
        while(true){
                init();
                int res = 0;
                for(int i=1;i<N+1;i++){
                        for(int j=1;j<N+1;j++){
                                if(input_arr[i][j] <= time){
                                        g[i][j]=0;
                                }else{
                                        g[i][j]=1;
                                }
                        }
                }
                time++;
                for(int i=1;i<N+1;i++){
                        for(int j=1;j<N+1;j++){
                                if(vis[i][j]==0){
                                        res = res + bfs(i,j);
                                }
                        }
                }
                answer.push(res);
                if(time==101)
                        break;
        }
        int biggest = 0;
        while(true){
                if(answer.empty()==true)
                        break;
                int ans_pop = answer.front();
                answer.pop();
                if(biggest < ans_pop){
                        biggest = ans_pop;
                }
        }
        cout << biggest << endl;
        return 0;
}
