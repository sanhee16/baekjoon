#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

#include <array>
#include <queue>
#include <stack>
#include <vector>

#define RED 1
#define BLUE 2
#define NONE 0

using namespace std;


int K,vertex,edge;
int* visited;
vector<int>* graph;


//void dfs(int u);


void dfs(int u){
        if(visited[u]==NONE){
                visited[u]=RED;
        }
        int v=-1;
        if(graph[u].size()==0)
                return ;
        for(int count=0;count<graph[u].size();count++){
                v=graph[u][count];
                if(visited[v]==NONE){
                        if(visited[u]==RED){
                                visited[v]=BLUE;
                        }else{
                                visited[v]=RED;
                        }
                dfs(v);

                }
        }

        return ;
}

bool test(){

        for(int u=0;u<vertex;u++){
                int count=0;
                while(true){
                        if(count==graph[u].size()){
                                break;
                        }
                        int v=graph[u][count];
                        if(visited[u]==visited[v]){
                                return false;

                        }
                        count++;
                }
        }
        return true;
}


int main(){

        queue<string> answer;
        cin >> K;
        for(int loop=0;loop<K;loop++){
                cin >> vertex >> edge;
                graph = new vector<int>[vertex];
                visited = new int[vertex];
                fill(visited,visited+vertex,NONE);
                int u,v;

                for(int e=0;e<edge;e++){
                        cin >> u >> v;
                        graph[u-1].push_back(v-1);
                        graph[v-1].push_back(u-1);
                }
                /*
                // all graph
                for(int i=0;i<vertex;i++){
                int x=0;
                cout << endl;
                while(true){
                if(x==graph[i].size())
                break;
                cout << graph[i][x]+1 << " ";
                x++;
                }
                }

                 */

                for(int i=0;i<vertex;i++){
                        if(visited[i]==NONE){
                                dfs(i);
                        }
                }

                //test
                bool res=test();
                if(res==true)
                        answer.push("YES");
                else
                        answer.push("NO");

                //last inital
                for(int i=0;i<vertex;i++){
                        graph[i].clear();
                        visited[i]=NONE;
                }
        }

        while(true){
                if(answer.empty()==true)
                        break;
                cout << answer.front()<<endl;
                answer.pop();

        }
        return 0;
}
