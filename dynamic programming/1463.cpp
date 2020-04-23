#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int DP[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;
    for(int i=2;i<=x;i++){
        DP[i]=DP[i-1]+1;
        if(i%3==0)DP[i]=min(DP[i/3]+1,DP[i]);
        if(i%2==0)DP[i]=min(DP[i/2]+1,DP[i]);
    }
    cout << DP[x] << endl;

    return 0;
}
