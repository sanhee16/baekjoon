#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
0000
0010
0000

1001
1011
1001
*/
int main() {
    int n, m;
    vector<int> t;
    vector<vector<int> > a;
    vector<vector<int> > b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        t.push_back(0);
    }
    for (int j = 0; j < n; j++) {
        a.push_back(t);
        b.push_back(t);
    }
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            a[i][j] = atoi(tmp.substr(j, 1).c_str());
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            b[i][j] = atoi(tmp.substr(j, 1).c_str());
        }
    }
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                for (int ii = i; ii < i + 3; ii++) {
                    for (int jj = j; jj < j + 3; jj++) {
                        if (a[ii][jj] == 1)
                            a[ii][jj] = 0;
                        else if (a[ii][jj] == 0)
                            a[ii][jj] = 1;
                    }
                }
                cnt++;
            }
            else {
                continue;
            }        
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cnt = -1;
                break;
            }
        }
    }

    cout << cnt;


    return 0;
}
