#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

pair<int,pair<int,string>> member[100000];

bool cmp(pair<int,pair<int,string> >a , pair<int,pair<int,string> > b){

        if(a.second.first < b.second.first){
                return true;
        }else if(a.second.first==b.second.first){
                if(a.first < b.first)
                        return true;
        }
        return false;

}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N=0;
        cin >> N;
        for(int i=0;i<N;i++){
                member[i].first=i;
                cin >> member[i].second.first >>  member[i].second.second;
        }
        sort(member,member+N,cmp);
        for(int i=0;i<N;i++)
                cout << member[i].second.first << " "<<  member[i].second.second << "\n";
        return 0;

}
