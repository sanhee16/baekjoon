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
#include <cstring>

using namespace std;
bool cmp(pair<int,int> a, pair<int, int> b) {
    if (a.second == b.second) {
        if (a.first <= b.first)
            return true;
        else
            return false;
    }
    else if (a.second < b.second) {
        return true;
    }
    else
        return false;
    return true;
}

int main() {
    int answer = 0;
    int n,a,b;
    vector<pair<int, int> > v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end(), cmp);
    int tt = 0;

    for (int i = 0; i < v.size(); i++) {
        if (tt <= v[i].first) {
            tt = v[i].second;
            answer++;
        }
    }
    cout << answer;
    return 0;
}
