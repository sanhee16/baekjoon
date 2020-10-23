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


int main() {
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v;
    int n, tmp;
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp < 0)
            v1.push_back(tmp);
        else if (tmp > 1)
            v2.push_back(tmp);
        else if (tmp == 0)
            v3.push_back(tmp);
        else if (tmp == 1)
            v4.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    int idx = 0;    
    while (v1.size() != 0) {
        if (idx == v1.size()-1) {
            if(v3.size()==0)
                v.push_back(v1[idx]);
            break;
        }
        else if (idx >= v1.size()) {
            break;
        }
        v.push_back(v1[idx] * v1[idx + 1]);
        idx += 2;
    }
    idx = 0;
    while (v2.size()!=0) {
        if (idx == v2.size() - 1) {
            v.push_back(v2[idx]);
            break;
        }
        else if (idx >= v2.size()) {
            break;
        }
        v.push_back(v2[idx] * v2[idx + 1]);
        idx += 2;
    }
    for (int i = 0; i < v4.size(); i++) {
        answer += v4[i];
    }
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    cout << answer;

    return 0;
}
