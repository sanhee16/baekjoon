#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <array>

using namespace std;

long long DP[2000000];

long long dp(int n){
        long long res=0;
        DP[n]=1;
        for(int i=n-1;i>=0;i--){
                DP[i] = (DP[i+1] + DP[i+2] + DP[i+3])%1000000009;
        }
        res = (DP[1]+DP[2]+DP[3])%1000000009;
        return res;
}
int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int T,n;
        cin >> T;
        queue<long long> ans;
        for(int i=0;i<T;i++){
                fill(DP,DP+2000000,0);
                cin >> n;
                ans.push(dp(n));
        }
        for(int i=0;i<T;i++){
                cout << ans.front()<<endl;
                ans.pop();
        }

        return 0;
}
