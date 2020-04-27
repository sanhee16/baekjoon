#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


int main(){
        int T;
        cin >> T;
        int biggest=2;

        pair<long long, long long> d[41];
        d[0] = make_pair(1,0);
        d[1] = make_pair(0,1);
        for(int i=0; i<T; i++){
                int N;
                cin >> N;
                if(biggest <= N){
                        for(int j=biggest;j<=N;j++){
                                d[j] = make_pair(d[j-1].first + d[j-2].first,
                                                d[j-1].second + d[j-2].second);
                        }
                        biggest = N;
                }
                cout << d[N].first << " " << d[N].second<< endl;
        }

        return 0;
}
