#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second){
        return true;
    }else if(a.second==b.second){
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
    pair<int,int>* p = new pair<int,int>[N];


    for(int i=0;i<N;i++)
        cin >> p[i].first >> p[i].second;

    sort(p,p+N,cmp);

    for(int i=0;i<N;i++)
        cout << p[i].first << " "<< p[i].second<<"\n";



    return 0;
}
