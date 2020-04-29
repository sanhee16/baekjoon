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
        long long d[10001][2] = {0};
        int drink[10001] = {0};
        for(int i=1;i<=n;i++)
                cin >> drink[i];

        d[1][0] = drink[1];
        d[1][1] = 1;


        for(int i=2;i<=n;i++){
                if(drink[i]==0){
                        d[i][1] = 1;
                        d[i][0] = d[i-1][0];
                }else{
                        if(d[i-1][1]==0){
                                long long temp = max(d[i-1][0], d[i-2][0]+drink[i]);
                                d[i][0] = max(temp, d[i-3][0]+drink[i-1]+drink[i]);
                                if(d[i][0] == d[i-3][0]+drink[i-1]+drink[i])
                                        d[i][1] = 0;
                                else
                                        d[i][1] = 1;

                        }else{
                                d[i][0] = d[i-1][0]+drink[i];
                                d[i][1] = 0;
                        }
                }

        }

        cout << d[n][0] << endl;
        return 0;

}
