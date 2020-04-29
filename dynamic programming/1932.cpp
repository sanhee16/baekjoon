#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <array>
#include <queue>

using namespace std;


int main(){

    int n;
    cin >> n;

    int tri[501][501] = {-1};
    long long num[501][501] = {0};


    for(int i=1; i<=n; i++){
        for(int j=1;j<=i;j++){
            cin >> tri[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==i){
                num[i][j] = num[i-1][j-1]+tri[i][j];
            }else if(j==1){
                num[i][j] = num[i-1][j]+tri[i][j];
            }else{
                num[i][j] = max(num[i-1][j-1]+tri[i][j],num[i-1][j]+tri[i][j]);
            }
        }
    }

    sort(num[n]+1,num[n]+n+1);
    cout << num[n][n]<< endl;

    return 0;
}
