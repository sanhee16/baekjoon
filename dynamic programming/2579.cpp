#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


int main(){

    int N;
    cin >> N;

    int d[2][301] = {0};
    int score[301] = {0};
    int ans1,ans2,ans = 0;

    for(int i=1;i<=N;i++){
        cin >> score[i];
    }

    d[0][N] = score[N];
    d[1][N] = score[N];

    d[0][N-1] = score[N]+score[N-1];
    d[1][N-1] = score[N];

    for(int i=N-2;i>=0;i--){
        d[0][i] = d[1][i+1] + score[i];
        d[1][i] = max(d[0][i+2]+ score[i],d[1][i+2]+ score[i]);
    }

    ans1 = max(d[0][1], d[1][1]);
    ans2 = max(d[0][2], d[1][2]);
    ans = max(ans1,ans2);
    cout << ans << endl;

    return 0;
}
