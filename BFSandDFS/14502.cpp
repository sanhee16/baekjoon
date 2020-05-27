#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <array>

using namespace std;
vector< vector <int> > first_g;
vector< vector <int> > g;
vector< vector <int> > vis;
int N,M;
vector<pair<int,int> > v;
vector< vector <int> > mid_g;


int ans=0;


void p_vec(vector< vector <int> > vec){
        cout << "-----vec-----" << endl;
        for(int i=0;i<vec.size();i++){
                for(int j=0;j<vec[i].size();j++){
                        cout << vec[i][j] << " ";
                }
                cout << endl;
        }
        cout << "-------------" << endl;
        return ;
}

void copy_vec(int a){
        for(int i=0;i<g.size();i++){
                for(int j=0;j<g[i].size();j++){
                        if(a==1)
                                g[i][j] = mid_g[i][j];
                        else if(a==2)
                                mid_g[i][j] = g[i][j];
                }
        }

}
void make_virus(){
        //p_vec(g);
        vector<int> nx = {1,-1,0,0};
        vector<int> ny = {0,0,1,-1};
        queue<pair<int,int> > q;
        for(int i=0;i<g.size();i++){
                        for(int j=0;j<g[i].size();j++){
                vis[i][j]=0;
                                }
        }
        for(int vt=0;vt<v.size();vt++){
                q.push(make_pair(v[vt].first,v[vt].second));
        }
        //cout << "q : " << q.size() << " -> " << endl;
        while(true){
                if(q.empty()==true)
                        break;
                int v_x, v_y;
                v_x = q.front().first;
                v_y = q.front().second;
                vis[v_x][v_y]=1;
                q.pop();

                for(int i=0;i<4;i++){
                        int x = v_x + nx[i];
                        int y = v_y + ny[i];
                        if(x<0 || y<0 || x>N-1 || y>M-1){
                                continue;
                        }
                        if(g[x][y]==0 && vis[x][y]==0){
                                g[x][y]=2;
                                q.push(make_pair(x,y));
                                vis[x][y]=1;
                        }else{
                                continue;
                        }
                }
        }
        //p_vec(g);
        return ;

}
void calc_result(){
        int cnt=0;
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        if(g[i][j]==0){
                                cnt++;
                        }
                }
        }
        if(ans < cnt){
                //p_vec(g);
                ans = cnt;
        }

        return ;
}

void set_wall(int start, int cnt){

        if(cnt==3){
                copy_vec(2);
                make_virus();
                calc_result();
                copy_vec(1);
                return ;
        }else{
                //set wall
                int x, y;
                for(int i=start;i<N*M;i++){
                        x = i/M;
                        y = i%M;
                        if(g[x][y]==0){
                                g[x][y]=1;
                                set_wall(start+1, cnt+1);
                                g[x][y]=0;
                        }
                }
        }
        return ;
}
void get_answer(){
        set_wall(0,0);
        cout << ans << endl;
        return ;
}


int main(){
        cin >> N >> M;
        vector<int> v1;
        vector<int> v2;
        int a;
        for(int j=0;j<M;j++)
                v2.push_back(0);

        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cin >> a;
                        v1.push_back(a);
                        if(a==2){
                                v.push_back(make_pair(i,j));
                        }
                }
                vis.push_back(v2);
                first_g.push_back(v1);
                g.push_back(v1);
                mid_g.push_back(v1);
                v1.clear();
        }
        get_answer();

        return 0;
}
