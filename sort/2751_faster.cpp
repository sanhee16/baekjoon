#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int n[1000000];

bool cmp(int a, int b){
    if(a < b){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N=0;
    cin >> N;


    for(int i=0;i<N;i++)
        cin >> n[i];

// fast : cmp > less<int>()
    sort(n,n+N,cmp);

    for(int i=0;i<N;i++)
        cout << n[i] <<"\n";



    return 0;
}
