#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <array>
#include <queue>

using namespace std;

// 1260


static int vertex, edge;
static int** arr;
int* visited;
int visited_count;

void bfs(int);

int main() {
        int answer = 0;
        cin >> vertex >> edge;
        arr = new int*[vertex];
        visited = new int[vertex];
        fill(visited, visited+vertex, 0);


        for (int i = 0; i < vertex; i++) {
                arr[i] = new int[vertex];
                fill(arr[i], arr[i] + vertex, 0);
        }
        int u,v;
        for (int i = 0; i < edge; i++) {
                cin >> u >> v ;
                arr[u-1][v-1]=1;
                arr[v-1][u-1]=1;
        }

        while(true){
                if(visited_count==vertex)
                        break;

                for (int i = 0; i < vertex; i++) {
                        if(visited[i]==0){
                                bfs(i+1);
                                answer++;
                        }
                }
        }

        cout << answer << endl;
        return 0;

}


void bfs(int start){
        queue<int> q;
        int u = 0;
        q.push(start);

        while(true){
                if(q.empty()==true)
                        break;
                u = q.front();
                q.pop();
                for(int v=1;v<vertex+1;v++){
                        if(arr[u-1][v-1]==1 && visited[u-1]==0){
                                q.push(v);
                        }

                }
                if(visited[u-1]==0){
                        visited_count++;
                        visited[u-1]=1;
                }
        }
        return ;
}


