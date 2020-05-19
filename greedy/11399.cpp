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

    vector<int> P;
    vector<int> ans;
    int N;
    cin >> N;
    int a=0;
    for(int i=0;i<N;i++){
        cin >> a;
        P.push_back(a);
    }

    sort(P.begin(), P.end(), less<int>());

    int total_time=0;
    for(int i=0;i<N;i++){
        total_time += P[i];
        ans.push_back(total_time);
    }

    total_time=0;
    for(int i=0;i<N;i++)
        total_time+= ans[i];
    cout << total_time << endl;

    return 0;
}
