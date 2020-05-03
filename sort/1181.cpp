#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<string> s;
bool cmp(string a, string b){
        if(a.length() < b.length()){
                return true;
        }else if(a.length() == b.length()){
                if(a>b)
                        return false;
                else if(a<b)
                        return true;
                else{
                        return false;
                }
        }else{
                return false;
        }

}


int main(){

        int n;
        cin >> n;

        string str[20000];
        for(int i=0;i<n;i++){
                cin >> str[i];
        }

        sort(str,str+n,cmp);
        string temp = "";
        for(int i=0;i<n;i++){
                if(str[i]==temp)
                        continue;
                cout << str[i] << endl;
                temp = str[i];
        }
        return 0;
}
