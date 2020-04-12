#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <array>
#include <queue>

using namespace std;

char g[102][102];
int N,M;
char vis[102][102];
void bfs();
long long count_dis[102][102];

void init(){
        for(int i=0;i<102;i++){
                for(int j=0;j<102;j++){
                        g[i][j]='2';
                        vis[i][j]='0';
                        count_dis[i][j]=0;
                }
        }
        return ;
}



int main(){
        init();
        cin >> N >> M;

        string str;
        for(int i=1;i<N+1;i++){
                cin >> str;
                for(int j=1;j<M+1;j++){
                        if(str[j-1]=='1')
                                g[i][j]='1';
                        else
                                g[i][j]='0';
                }
        }
        /*
           for(int i=0;i<N+2;i++){
           for(int j=0;j<M+2;j++){
           cout << g[i][j] << " ";
           }
           cout << endl;
           }
         */
        bfs();
        cout << count_dis[N][M];
/*
        for(int i=0;i<N+2;i++){
                for(int j=0;j<M+2;j++){
                        cout << int(count_dis[i][j]) << " ";
                }
                cout << endl;
        }
*/
        return 0;
}

void bfs(){

        queue<pair<int,int>> q;
        q.push(make_pair(1,1));
        int i,j;


        i = q.front().first;
        j = q.front().second;
        q.pop();
        vis[i][j]='1';

        q.push(make_pair(i,j+1));
        q.push(make_pair(i+1,j));
        q.push(make_pair(i-1,j));
        q.push(make_pair(i,j-1));

        count_dis[i][j]=1;

        count_dis[i+1][j]=count_dis[i][j]+1;
        count_dis[i-1][j]=count_dis[i][j]+1;
        count_dis[i][j+1]=count_dis[i][j]+1;
        count_dis[i][j-1]=count_dis[i][j]+1;
        vis[i+1][j]='1';
        vis[i-1][j]='1';
        vis[i][j+1]='1';
        vis[i][j-1]='1';

        while(true){
                if(q.empty()==true)
                        break;
                i = q.front().first;
                j = q.front().second;
                q.pop();

                if(g[i][j]!='1'){
                        count_dis[i][j]=0;
                        continue;
                }

                if(g[i][j]=='1'){
                        /*
                           q.push(make_pair(i,j+1));
                           q.push(make_pair(i+1,j));
                           q.push(make_pair(i-1,j));
                           q.push(make_pair(i,j-1));

                           count_dis[i+1][j]=count_dis[i][j]+1;
                           count_dis[i-1][j]=count_dis[i][j]+1;
                           count_dis[i][j+1]=count_dis[i][j]+1;
                           count_dis[i][j-1]=count_dis[i][j]+1;
                         */
                        if(vis[i+1][j]=='0'){
                                count_dis[i+1][j]=count_dis[i][j]+1;
                                vis[i+1][j]='1';
                                q.push(make_pair(i+1,j));

                        }
                        if(vis[i-1][j]=='0'){
                                count_dis[i-1][j]=count_dis[i][j]+1;
                                vis[i-1][j]='1';
                                q.push(make_pair(i-1,j));

                        }
                        if(vis[i][j+1]=='0'){
                                count_dis[i][j+1]=count_dis[i][j]+1;
                                vis[i][j+1]='1';
                                q.push(make_pair(i,j+1));

                        }
                        if(vis[i][j-1]=='0'){
                                count_dis[i][j-1]=count_dis[i][j]+1;
                                vis[i][j-1]='1';
                                q.push(make_pair(i,j-1));

                        }
                }
        }

}
