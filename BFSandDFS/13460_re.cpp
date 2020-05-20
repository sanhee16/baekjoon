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
#include<cstdio>

using namespace std;
char b[10][10];
int ans = 11;
void move_func(int rx, int ry, int bx, int by, int mx, int my, int move_num){
        int rm=0;
        int bm=0;
        if(move_num >= 11)
                return ;
        if(mx!=my){
                while(true){
                        if(b[bx+mx][by+my]=='#')
                                break;
                        bx+=mx;
                        by+=my;
                        bm++;
                        if(b[bx][by]=='O'){
                                return;
                        }
                }

                while(true){
                        if(b[rx+mx][ry+my]=='#'){
                                break;
                        }
                        rx+=mx;
                        ry+=my;
                        rm++;
                        if(b[rx][ry]=='O'){
                                if(ans > move_num)
                                        ans = move_num;
                                return;
                        }
                }
        }
        if(bx==rx && by==ry){
                if(bm>rm){
                        bx-=mx;
                        by-=my;
                }
                else{
                        rx-=mx;
                        ry-=my;
                }
        }
        if(mx==0){
                move_func(rx,ry,bx,by,1,0,move_num+1);
                move_func(rx,ry,bx,by,-1,0,move_num+1);
        }
        if(my==0){
                move_func(rx,ry,bx,by,0,1,move_num+1);
                move_func(rx,ry,bx,by,0,-1,move_num+1);
        }

}




int main(){

        int N,M;
        int rx=0,ry=0,bx=0,by=0;
        cin >> N >> M;


        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cin >> b[i][j];
                        if(b[i][j]=='R'){
                                rx=i;
                                ry=j;
                        }
                        if(b[i][j]=='B'){
                                bx=i;
                                by=j;
                        }
                }
        }

        move_func(rx,ry,bx,by,0,0,0);

        if(ans == 11)
                ans = -1;
        cout << ans << endl;
        return 0;

}
