#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <functional>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main(){
    int n;
    cin >> n;
    vector<pll> x;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        x.push_back({ a,b });
        sum += b;
    }
    sort(x.begin(), x.end());
    sum = ceil((float)sum/2);
    ll tmp = 0;
    int idx = 0;
    while (tmp < sum) {
        tmp += x[idx].second;
        idx++;
    }
    cout << x[idx - 1].first;
    return 0;
} 
