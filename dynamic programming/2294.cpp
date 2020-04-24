#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        queue<int> ans;
        int n,k;
        cin>>n>>k;
        int DP[10001];
        int coin[10001];
        fill(DP,DP+10001,20000);
        fill(coin,coin+10001,0);

        DP[0]=0;
        int m;
        for(int a=1;a<=n;a++){
                cin>>coin[a];
                if(coin[a]>10000){
                        coin[a]=0;
                }
        }
        for(int i=1;i<=n;i++){
                for(int j=coin[i];j<=k;j++){
                        DP[j] = min(DP[j], DP[j-coin[i]]+1);
                }
        }
        if(DP[k]==20000)
                cout << -1 << "\n";
        else
                cout << DP[k] << "\n";

        return 0;
}

