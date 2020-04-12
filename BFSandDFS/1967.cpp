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

int vis[100001];
int lv[100001];

int N,K;

void init(){
        fill(vis,vis+100001,0);
        fill(lv,lv+100001,0);
        return ;
}

int bfs(){
        queue<int> q;
        q.push(N);
        int v=0;
        while(true){
                v = q.front();
                if(v==K){
                        return lv[v];
                }
                if(v+1 >= 0 && v+1 <= 100000){
                        if(vis[v+1]==0){
                                vis[v+1]=1;
                                q.push(v+1);
                                lv[v+1]=lv[v]+1;
                        }
                }
                if(v-1 >= 0 && v-1 <= 100000){
                        if(vis[v-1]==0){
                                vis[v-1]=1;
                                q.push(v-1);
                                lv[v-1]=lv[v]+1;
                        }
                }
                if(2*v >= 0 && 2*v <= 100000){
                        if(vis[2*v]==0){
                                vis[2*v]=1;
                                q.push(2*v);
                                lv[2*v]=lv[v]+1;
                        }

                }
                q.pop();
                vis[v]=1;
        }
        return 0;

}

int main(){
        init();
        cin >> N >> K;

        int res = bfs();
        cout << res << endl;


        return 0;
}
