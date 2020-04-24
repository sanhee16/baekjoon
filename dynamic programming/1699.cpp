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

    long long DP[100001];
    fill(DP,DP+100001,10000000001);
    int n=0;
    cin >> n;

    DP[0]=0;

    for(int i=1;i<=n;i++){
        if(i*i > n)
            break;
        for(long long j=i*i;;j++){
            if(j > n)
                break;
            DP[j] = min(DP[j], DP[j-i*i]+1);
        }
    }

    cout << DP[n] << "\n";


    return 0;
}

