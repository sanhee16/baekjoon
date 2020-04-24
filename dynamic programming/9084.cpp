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
        int K,n;
        cin >> K;
        for(int loop = 0; loop<K; loop++){
                cin>>n;
                int DP[10001];
                int coin[10001];
                fill(DP,DP+10001,0);
                fill(coin,coin+10001,0);

                DP[0]=1;
                int m;
                for(int a=1;a<=n;a++){
                        cin>>coin[a];
                }
                cin >> m;
                for(int i=1;i<=n;i++){
                        for(int j=coin[i];j<=m;j++){
                                DP[j] = DP[j]+ DP[j-coin[i]];
                        }
                }
                ans.push(DP[m]);
        }

        for(int loop = 0; loop<K; loop++){
                cout << ans.front() << "\n";
                ans.pop();
        }
        return 0;
}
