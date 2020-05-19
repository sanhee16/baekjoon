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
int N,M;
int board[10][10];
int b[10][10];
int no_blue = 0;
int min_time = 11;
queue<pair<int,int>> red;
queue<pair<int,int>> blue;

int bfs(){

        int ans=-1;
        queue<int> move_count;

        vector<pair<int,int>> move;
        move.push_back(make_pair(0,-1)); // up
        move.push_back(make_pair(0,1)); // down

        move.push_back(make_pair(-1,0)); // left
        move.push_back(make_pair(1,0)); // right


        move_count.push(0);
        pair<int,int> loc_red;
        pair<int,int> loc_blue;
        int cur_count=0;

        while(true){
                if(red.empty()==true)
                        break;

                loc_red = red.front();
                loc_blue = blue.front();
                cur_count = move_count.front();
                red.pop();
                blue.pop();
                move_count.pop();
                if(cur_count >= 10){
                        continue;
                }

                for(int i=0;i<4;i++){
                        for(int j=0;j<10;j++){
                                for(int i=0;i<10;i++){
                                        board[i][j]=b[i][j];
                                }
                        }

                        int a1=0; int b1=0;
                        int a2=0; int b2=0;
                        int a_type=0; int b_type=0;

                        if(i==0 || i==1){
                                // move y
                                if(loc_red.first == loc_blue.first){
                                        if(((loc_red.second > loc_blue.second) && (i==0)) ||
                                                        ((loc_red.second < loc_blue.second) && (i==1))){
                                                //B
                                                //R
                                                // move B first
                                                a1 = loc_blue.first;
                                                a2 = loc_blue.second;
                                                b1 = loc_red.first;
                                                b2 = loc_red.second;

                                                a_type = 2;
                                                b_type = 1;

                                        }else{
                                                // move R first
                                                //R
                                                //B
                                                a1 = loc_red.first;
                                                a2 = loc_red.second;
                                                b1 = loc_blue.first;
                                                b2 = loc_blue.second;

                                                a_type = 1;
                                                b_type = 2;
                                        }
                                }else{

                                        a1 = loc_blue.first;
                                        a2 = loc_blue.second;
                                        b1 = loc_red.first;
                                        b2 = loc_red.second;
                                        a_type = 2;
                                        b_type = 1;
                                }
                        }else if(i==2 || i==3){
                                if(loc_red.second == loc_blue.second){
                                        if(((loc_red.first > loc_blue.first) && (i==3)) ||
                                                        ((loc_red.first < loc_blue.first) && (i==2))){
                                                //BR-> || RB <-
                                                //move R first
                                                a1 = loc_red.first;
                                                a2 = loc_red.second;
                                                b1 = loc_blue.first;
                                                b2 = loc_blue.second;

                                                a_type = 1;
                                                b_type = 2;

                                        }else{
                                                //RB-> || BR <-
                                                // move B first
                                                a1 = loc_blue.first;
                                                a2 = loc_blue.second;
                                                b1 = loc_red.first;
                                                b2 = loc_red.second;

                                                a_type = 2;
                                                b_type = 1;
                                        }
                                }
                                else{
                                        a1 = loc_blue.first;
                                        a2 = loc_blue.second;
                                        b1 = loc_red.first;
                                        b2 = loc_red.second;

                                        a_type = 2;
                                        b_type = 1;
                                }
                        }
                        //board[a1][a2] = a_type;
                        board[b1][b2] = b_type;
                        int s1=0;
                        int s2=0;
                        int no_input = 0;
                        int pass = 0;
                        int red_pass=0;
                        int blue_pass=0;
                        board[a1][a2] = 0;
                        while(true){
                                a1 = a1 + move[i].first;
                                a2 = a2 + move[i].second;
                                if(board[a1][a2]==0){
                                        s1=1;
                                        // board[a1][a2] == .
                                        continue;
                                }
                                if(board[a1][a2]==100){
                                        s1=1;
                                        pass=1;
                                        no_input=1;
                                        if(a_type==1){
                                                red_pass=1;
                                        }else{
                                                blue_pass=1;
                                        }
                                        break;
                                }
                                else{
                                        // board[a1][a2] == # or b_type
                                        a1 = a1 - move[i].first;
                                        a2 = a2 - move[i].second;
                                        board[a1][a2] = a_type;
                                        break;
                                }
                        }
                        board[b1][b2] = 0;
                        while(true){
                                b1 = b1 + move[i].first;
                                b2 = b2 + move[i].second;
                                if(board[b1][b2]==0){
                                        s2=1;
                                        continue;
                                }
                                if(board[b1][b2]==100){
                                        s2=1;
                                        no_input=1;
                                        if(b_type==1){
                                                red_pass=1;
                                        }else{
                                                blue_pass=1;
                                        }
                                        break;
                                        /*if(b_type==1 && pass==0){
                                                // red -> O
                                                // success
                                                if(min_time > cur_count+1)
                                                        min_time = cur_count+1;
                                                break;
                                        }
                                        */
                                }else{
                                        b1 = b1 - move[i].first;
                                        b2 = b2 - move[i].second;
                                        board[b1][b2] = b_type;
                                        break;
                                }
                        }

                        if(red_pass==1 && blue_pass==0){
                                if(min_time > cur_count+1)
                                        min_time = cur_count+1;
                        }

                        if(s1 == 0 && s2 == 0){
                                //no move
                                continue;
                        }
                        if(no_input==1){
                                //enter to the hole
                                continue;
                        }
                        if(cur_count==10){
                                continue;
                        }

                        if(a_type==1){
                                red.push(make_pair(a1,a2));
                                blue.push(make_pair(b1,b2));
                        }else{
                                red.push(make_pair(b1,b2));
                                blue.push(make_pair(a1,a2));
                        }
                        move_count.push(cur_count+1);
                }//for loop

        }//while loop
        if(min_time < 11)
                return min_time;
        return ans;
}

int main(){

        cin >> N >> M;
        char a;
        for(int j=0;j<10;j++){
                for(int i=0;i<10;i++){
                        board[i][j]=-1;
                        b[i][j]=-1;
                }
        }
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cin >> a;
                        if(a == '#'){
                                b[i][j]=-1;
                                board[i][j]     = -1;
                        }else if(a == '.'){
                                b[i][j]=0;
                                board[i][j] = 0;
                        }else if(a == 'R'){
                                b[i][j]=0;
                                board[i][j] = 0;
                                red.push(make_pair(i,j));
                        }else if(a == 'B'){
                                b[i][j]=0;
                                board[i][j] = 0;
                                blue.push(make_pair(i,j));
                        }else if(a== 'O'){
                                b[i][j]=100;
                                board[i][j] = 100;
                        }
                }
        }
        if(red.empty()==true)
                return -1;
        if(blue.empty()==true){
                blue.push(make_pair(100,100));
                no_blue=1;
        }
        /*
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cout << board[i][j] << "\t";
                }
                cout << endl;
        }*/
        cout << bfs() <<endl;
        /*
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cout << board[i][j] << "\t";
                }
                cout << endl;
        }*/

        return 0;
}
