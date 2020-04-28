#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    long long d[1001];
    fill(d,d+1001,0);
    d[1]=1;
    d[2]=2;

    for(int i=3;i<=n;i++){
        d[i] = (d[i]+d[i-1]+d[i-2])%10007;
    }
    cout << d[n]<<endl;
    return 0;
}
