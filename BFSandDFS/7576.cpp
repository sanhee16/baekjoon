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

int vis[1002][1002];
int box[1002][1002];
int M,N=0;
vector<pair<int,int>> dir;

int bfs(){
        queue<pair<int,int>> q;
        queue<int> time;
        for(int i=1;i<N+1;i++){
                for(int j=1;j<M+1;j++){
                        if(box[i][j]==1){
                                vis[i][j]=1;
                                q.push(make_pair(i,j));
                                time.push(0);
                        }
                }
        }

        int x,y=0;
        int next_x,next_y=0;
        int t=0;
        int largest=0;
        while(true){
                if(q.empty()==true){
                        break;
                }
                x = q.front().first;
                y = q.front().second;
                t = time.front();
                q.pop();
                time.pop();
                //vis[x][y]=1;

                for(int i=0;i<4;i++){
                        next_x = x + dir[i].first;
                        next_y = y + dir[i].second;
                        if(box[next_x][next_y]==-2){
                                continue;
                        }
                        if(vis[next_x][next_y]==0){
                                if(box[next_x][next_y]==1){
                                        continue;
                                }else if(box[next_x][next_y]==0){
                                        q.push(make_pair(next_x,next_y));
                                        time.push(t+1);
                                        if(largest < t+1)
                                                largest = t+1;
                                        vis[next_x][next_y]=1;
                                        box[next_x][next_y]=1;
                                }else if(box[next_x][next_y]==-1){
                                        continue;
                                }
                        }
                }
        }
        for(int i=1;i<N+1;i++){
                for(int j=1;j<M+1;j++){
                        if(box[i][j]==0){
                                largest=-1;
                                break;
                        }
                }
        }

        return largest;
}

int main(){

        dir.push_back(make_pair(-1,0));
        dir.push_back(make_pair(1,0));
        dir.push_back(make_pair(0,-1));
        dir.push_back(make_pair(0,1));

        cin >> M >> N ;

        for(int i=0;i<1002;i++){
                for(int j=0;j<1002;j++){
                        vis[i][j]=0;
                        box[i][j]=-2;
                }
        }

        for(int i=1;i<N+1;i++){
                for(int j=1;j<M+1;j++){
                        cin >> box[i][j];
                }
        }

        int res = bfs();
        cout << res << endl;

        return 0;
}
