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

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N;
        cin >> N;
        int num[100001] = {0};
        int d_max[2][100001] = {0};
        int d_min[2][100001] = {0};

        for(int i=1;i<=3;i++){
                cin >> num[i];
                d_max[0][i] = num[i];
                d_min[0][i] = num[i];
        }
        if(N==1){
                for(int i=1;i<=3;i++){
                        d_max[1][i] = d_max[0][i];
                        d_min[1][i] = d_min[0][i];
                }
        }else{
                for(int i=2;i<=N;i++){
                        for(int j=1;j<=3;j++){
                                cin >> num[j];
                                if(j==1){
                                        d_max[1][j] = max(d_max[0][j]+num[j],d_max[0][j+1]+num[j]);
                                        d_min[1][j] = min(d_min[0][j]+num[j],d_min[0][j+1]+num[j]);
                                }else if(j==3){
                                        d_max[1][j] = max(d_max[0][j-1]+num[j],d_max[0][j]+num[j]);
                                        d_min[1][j] = min(d_min[0][j-1]+num[j],d_min[0][j]+num[j]);
                                }else{
                                        int temp = max(d_max[0][j]+num[j],d_max[0][j+1]+num[j]);
                                        d_max[1][j] = max(d_max[0][j-1]+num[j],temp);
                                        temp = min(d_min[0][j]+num[j],d_min[0][j+1]+num[j]);
                                        d_min[1][j] = min(d_min[0][j-1]+num[j],temp);
                                }
                        }
                        for(int j=1;j<=3;j++){
                                d_max[0][j] = d_max[1][j];
                                d_min[0][j] = d_min[1][j];
                        }
                }
        }
        sort(d_max[1]+1,d_max[1]+1+3);
        cout << d_max[1][3] << " ";

        sort(d_min[1]+1,d_min[1]+1+3);
        cout << d_min[1][1] << endl;

        return 0;
}
