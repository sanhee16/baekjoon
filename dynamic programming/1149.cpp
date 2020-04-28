#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


int main(){
    int n;
    int cost[3][1001];
    for(int j=0;j<=2;j++){
        cost[j][0]=0;
        cost[j][1]=0;
    }
    int d[3][1001];
    for(int j=0;j<=2;j++){
        d[j][0] = 0;
    }
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++){
            cin >> cost[j][i];
        }
    }


    for(int i=1;i<=n; i++){
        d[0][i] = min(d[1][i-1]+cost[0][i], d[2][i-1]+cost[0][i]);
        d[1][i] = min(d[0][i-1]+cost[1][i], d[2][i-1]+cost[1][i]);
        d[2][i] = min(d[0][i-1]+cost[2][i], d[1][i-1]+cost[2][i]);
    }
    /*
    for(int i=1;i<=n; i++){
        cout << d[i].first << " " << d[i].second << endl;
    }
    */
    int ans = min(d[0][n],d[1][n]);
    ans = min(ans,d[2][n]);
    cout << ans << endl;

    return 0;
}
