
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string.h>
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


int g[52][52];
int vis[52][52];


int dfs(int i, int j, int w);
void init(){
        for(int i=0;i<52;i++){
                for(int j=0;j<52;j++){
                        g[i][j]=-1;
                        vis[i][j]=0;
                }
        }
}
int main(){

        int w,h;
        queue<int> answer;
        while(true){
                cin >> w >> h;

                if(w==0 && h==0)
                        break;
                init();
                int v;
                int x=1;
                int y=1;
                for(int i=1;i<h*w+1;i++){
                        if(i%w==1 && i!=1){
                                x++;
                                y=1;
                        }
                        cin >> v;
                        g[x][y] = v;
                        y++;
                }
                int res=0;
                for(int i=1;i<h+1;i++){
                        for(int j=1;j<w+1;j++){
                                if(vis[i][j]==0){
                                        res += dfs(i,j,w);
                                }
                        }
                }
                answer.push(res);
        }
        while(true){
                if(answer.empty()==true)
                        break;
                cout << answer.front()<<endl;
                answer.pop();
        }

        return 0;
}


int dfs(int i, int j, int w){
        if(vis[i][j]==0){
                vis[i][j]=1;
        }
        if(g[i][j]==0){
                return 0;
        }
        vector<pair<int,int>> adj;
        adj.push_back(make_pair(i,j-1));
        adj.push_back(make_pair(i,j+1));
        adj.push_back(make_pair(i+1,j));
        adj.push_back(make_pair(i-1,j));

        adj.push_back(make_pair(i+1,j-1));
        adj.push_back(make_pair(i-1,j-1));
        adj.push_back(make_pair(i-1,j+1));
        adj.push_back(make_pair(i+1,j+1));

        int u;
        int v;
        int count=0;
        for(int i=0;i<8;i++){
                u = adj[i].first;
                v = adj[i].second;
                if(vis[u][v]==0 && g[u][v]!=-1){
                        dfs(u,v,w);
                }
        }
        return 1;
}

