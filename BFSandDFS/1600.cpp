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


int g[202][202];
int vis[202][202][31];
int t[202][202];
int W,H = 0;
int K=0;
queue<int> answer;



void bfs(){
        // K and move.push_backtimes
        queue<pair<int,int>> info;
        queue<pair<int,int>> q;
        int x,y=0;
        q.push(make_pair(1,1));
        info.push(make_pair(K,0));
        vis[1][1][K]=1;


        vector<pair<int,int>> move;
        move.push_back(make_pair(1,0));
        move.push_back(make_pair(-1,0));
        move.push_back(make_pair(0,1));
        move.push_back(make_pair(0,-1));

        move.push_back(make_pair(1,2));
        move.push_back(make_pair(-1,2));
        move.push_back(make_pair(2,1));
        move.push_back(make_pair(-2,1));

        move.push_back(make_pair(-1,-2));
        move.push_back(make_pair(1,-2));
        move.push_back(make_pair(-2,-1));
        move.push_back(make_pair(2,-1));

        int x_next, y_next=0;
        int left_k, move_time=0;

        while(true){
                if(q.empty()==true)
                        break;
                x=q.front().first;
                y=q.front().second;
                left_k=info.front().first;
                move_time=info.front().second;

                q.pop();
                info.pop();
                //vis[x][y]=1;

                for(int i=0;i<12;i++){
                        x_next = x + move[i].first;
                        y_next = y + move[i].second;
                        if(x_next<1 || y_next<1 || x_next>H || y_next>W || g[x_next][y_next]==1 || g[x_next][y_next]==-1){
                                //cout << "out : " << x_next <<","<<y_next<<"(" << g[x_next][y_next] <<")" <<endl;
                                continue;
                        }

                        if(g[x_next][y_next]==0){
                                if(i<4){
                                        if(vis[x_next][y_next][left_k]==0){
                                                if(x_next==H && y_next==W){
                                                        answer.push(move_time+1);
                                                }else{
                                                        info.push(make_pair(left_k,move_time+1));
                                                        q.push(make_pair(x_next,y_next));
                                                        vis[x_next][y_next][left_k]=1;
                                                        t[x_next][y_next]=move_time+1;
                                                }
                                        }
                                }if( 3<i && left_k>0){
                                        if(vis[x_next][y_next][left_k-1]==0){
                                                if(x_next==H && y_next==W){
                                                        answer.push(move_time+1);
                                                }
                                                else{
                                                        info.push(make_pair(left_k-1,move_time+1));
                                                        q.push(make_pair(x_next,y_next));
                                                        vis[x_next][y_next][left_k-1]=1;
                                                        t[x_next][y_next]=move_time+1;
                                                }
                                        }
                                }
                        }
                }
        }
        return ;
}


int main(){
        for(int i=0; i<202; i++){
                for(int j=0;j<202;j++){
                        g[i][j]=-1;
                        t[i][j]=-100;
                        for(int k=0;k<31;k++){
                                vis[i][j][k]=0;
                        }
                }
        }

        cin >> K;
        cin >> W >> H;

        for(int i=1; i<H+1; i++){
                for(int j=1;j<W+1;j++){
                        cin >> g[i][j];
                }
        }
        /*
           cout << "----------" << endl;
           for(int i=0; i<H+2; i++){
           for(int j=0;j<W+2;j++){
           cout<< g[i][j]<<" ";
           }
           cout << endl;
           }

           cout << endl << endl;
         */
        if(W==1 && H==1){
                cout << 0 << endl;
                return 0;
        }

        bfs();

        int res=1000000;
        while(true){
                if(answer.empty()==true)
                        break;
                if(answer.front() < res){
                        res = answer.front();
                }
                answer.pop();
        }
        if(res == 1000000){
                res=-1;
        }
        cout << res << endl;



        return 0;
}
