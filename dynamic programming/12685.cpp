#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <array>

using namespace std;

int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N,K;
        cin >> N >> K;

        pair<int,int> t[100];
        vector<vector <int> > DP;

        for(int col = 0; col<1001; col++){
                DP.push_back(vector<int>());
                for(int row = 0; row<K+1; row++){
                        DP.at(col).push_back(0);
                }
        }


        for(int i=1;i<N+1;i++){
                cin >> t[i].first >> t[i].second ;
        }

        sort(t+1,t+N+1);
        for(int i=1;i<N+1;i++){
                for(int j=1;j<K+1;j++){
                        if(j-t[i].first >= 0){
                                DP[i][j] = max(DP[i-1][j], DP[i-1][j-t[i].first]+t[i].second);
                        }else{
                                DP[i][j] = DP[i-1][j];
                        }
                }
        }
        for(int i=1;i<N+1;i++){
                for(int j=1;j<K+1;j++){
                        cout << DP[i][j] << " ";
                }
                cout << endl;
        }
        cout << DP[N][K]<<endl;
        return 0;
}

