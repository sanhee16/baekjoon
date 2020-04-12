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

int g[1001][1001];
int vis[1001];
int arr[1001];
void bfs(int u,int N){
        vis[u]=1;
        queue<int> q;
        q.push(u);
        int start = u;
        int pi=0;
        while(true){
                pi = arr[u];
                vis[u]=1;
                if(pi==start)
                        break;
                u = pi;
        }
        return;
        return;
}
void init(int N){
        fill(arr,arr+1001,0);
        fill(vis,vis+1001,0);
        return ;
}
int main(){

        int K;
        cin >> K;
        queue<int> answer;
        for(int loop=0;loop<K;loop++){
                int N;
                int num=0;
                cin >> N;
                init(N);

                int vertex;
                for(int i=0;i<N;i++){
                        cin >> vertex;
                        arr[i+1]=vertex;
                }

                for(int i=1;i<N+1;i++){
                        if(vis[i]==0){
                                bfs(i,N);
                                num++;
                        }
                }
                answer.push(num);
        }
        while(true){
                if(answer.empty()==true)
                        break;
                cout << answer.front()<<endl;
                answer.pop();
        }

        return 0;
}
