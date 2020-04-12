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

void init(){
        //fill(vis,vis+0x800000,0);
        //fill(order,order+0x800000,0);
        return ;
}

string A;
int P;

string calc(string num);

long long bfs(){
        vector<string> vec;
        string res = A;
        long long count = 1;
        int same=0;
        vec.push_back(res);

        while(true){
                res = calc(res);
                if(vec.empty()==false){
                        for(long long i=0;i<count;i++){
                                if(vec[i]==res){
                                        return i;
                                }
                        }
                }
                vec.push_back(res);
                count++;
        }
}

string calc(string num){

        long long res=0;
        int t=0;
        //long long di = 10*num.length();
        while(t!=num.length()){
                long digit = 0;
                if(num[t]=='0'){
                        digit=0;
                }else if(num[t]=='1'){
                        digit=1;
                }else if(num[t]=='2'){
                        digit=2;
                }
                else if(num[t]=='3'){
                        digit=3;
                }
                else if(num[t]=='4'){
                        digit=4;
                }
                else if(num[t]=='5'){
                        digit=5;
                }
                else if(num[t]=='6'){
                        digit=6;
                }
                else if(num[t]=='7'){
                        digit=7;
                }
                else if(num[t]=='8'){
                        digit=8;
                }
                else if(num[t]=='9'){
                        digit=9;
                }

                t++;

                if(digit==0)
                        continue;
                long long digit_res = digit;
                for(int i=1;i<P;i++){
                        digit_res = digit_res*digit;
                }
                res = digit_res+res;
        }
        string return_res = to_string(res);
        return return_res;
}
int main(){

        init();
        cin >> A >> P;
        long long res=-1;
        //string res = calc(A);
        res = bfs();
        cout << res << endl;

        return 0;
}
