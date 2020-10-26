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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    int n;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    /*
    5
    15 10 18 20 13
    */
    sort(v.begin(), v.end());
    int cmp = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (cmp < (n - i) * v[i]) {
            cmp = (n - i) * v[i];
            cnt = n - 1;
        }
    }
    cout << cmp;


    return 0;
} 
