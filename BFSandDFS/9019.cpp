#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int vis[10000];
int before_num[10000];
string min_inst[10000];


void bfs(int x, int y){
        queue<int> num;
        num.push(x);
        vis[x]=1;
        before_num[x]=-1;

        int cur_num=0;
        int next_num=0;
        string next_inst="";
        int d1,d2,d3,d4=0;

        while(true){
                if(num.empty()==true)
                        break;
                cur_num = num.front();
                num.pop();
                if(cur_num==y)
                        break;

                d1 = cur_num/1000;
                d2 = (cur_num - d1*1000)/100;
                d3 = (cur_num - d1*1000 - d2*100)/10;
                d4 = (cur_num - d1*1000 - d2*100 - d3*10);

                for(int i=0;i<4;i++){
                        if(i==0){
                                if((2*cur_num)>9999){
                                        next_num = (2*cur_num) % 10000;
                                }else{
                                        next_num = 2*cur_num;
                                }
                                next_inst = 'D';
                        }else if(i==1){
                                if(cur_num==0){
                                        next_num=9999;
                                }else{
                                        next_num=cur_num-1;
                                }
                                next_inst = 'S';
                        }else if(i==2){
                                next_num = d2*1000+d3*100+d4*10+d1;
                                next_inst = 'L';
                        }else{
                                next_num = d4*1000+d1*100+d2*10+d3;
                                next_inst = 'R';
                        }
                        if(vis[next_num]==0){
                                min_inst[next_num] = next_inst;
                                num.push(next_num);
                                before_num[next_num]=cur_num;
                                vis[next_num]=1;
                                if(y==next_num){
                                        return ;
                                }
                        }
                }
        }
        return ;
}

void init(){
        for(int i=0;i<10000;i++){
                vis[i]=0;
                min_inst[i]="";
                before_num[i]=0;
        }
        return ;
}
int main(){
        queue<string> ans;
        int K=0;
        cin >> K;
        int x,y=0;
        for(int loop=0;loop<K;loop++){
                init();
                x,y=0;
                cin >> x >> y;
                bfs(x,y);
                string temp="";
                int before = y;
                while(true){
                        if(before==-1)
                                break;
                        temp = temp+min_inst[before];
                        before = before_num[before];
                }
                string answer="";
                for(int i=temp.length()-1;i>-1;i--){
                        answer = answer + temp[i];
                }
                ans.push(answer);
        }
        for(int loop=0;loop<K;loop++){
                cout << ans.front() << endl;
                ans.pop();
        }
        return 0;
}
