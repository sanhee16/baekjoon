#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
using namespace std;


int main(){
    vector<int> dx = { 1,2,2,1 };
    vector<int> dy = { 2,1,-1,-2 };
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    
    if (n < 2 || m < 2) {
        cnt = 1;
    }
    else if (n == 2) {
        cnt = min(4, (m - 1) / 2 + 1);
    }
    else if (n > 2 && m < 7) {
        cnt = min(4, m);
    }
    else if (n > 2 && m >= 7) {        
        cnt = m - 2;
    }

    cout << cnt;
    return 0;
} 
