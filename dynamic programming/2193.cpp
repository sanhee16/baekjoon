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


    int N;
    cin >> N;
    long long d[2][91] = {0};
    if(N<3){
        cout << 1 << endl;
        return 0;
    }else{
        d[0][3]=1;
        d[1][3]=1;
        for(int i=4; i<=N; i++){
            d[0][i] = d[0][i-1] + d[1][i-1];
            d[1][i] = d[0][i-1];
        }
    }

    cout << d[0][N] + d[1][N] << endl;

    return 0;
}
