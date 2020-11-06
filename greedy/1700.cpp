#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
	int n, k, tmp;
	vector<int> v;
	int answer = 0;
	unordered_map<int, int> m;
	cin >> n >> k;
	vector<int> ans(n,0);
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		m[tmp]++;
		v.push_back(tmp);
	}
	for (int i = 0; i < k; i++) {
		int put = 0;
		int val = v[i];

		for (int j = 0; j < n; j++) {
			if (ans[j] == 0 || ans[j] == val) {
				ans[j] = val;
				m[ans[j]]--;
				put = 1;
				break;
			}
		}
		if (put == 1)
			continue;

		if (put == 0) {
			for (int j = 0; j < n; j++) {
				if (m[ans[j]] == 0) {
					ans[j] = val;
					m[ans[j]]--;
					put = 1;
					answer++;
					break;
				}
			}
		}
		if (put == 0) {
			vector<int> chk(n, 0);
			int cnt = 0;
			for (int j = i+1; j < k; j++) {
				if (cnt == n - 1) {
					for (int x = 0; x < n; x++) {
						if (chk[x] == 0) {
							ans[x] = val;
							m[ans[x]]--;
							
							answer++;
							break;
						}
					}
					break;
				}
				for (int x = 0; x < n; x++) {
					if (ans[x] == v[j] && chk[x]==0) {
						chk[x] = 1;
						cnt++;
						break;
					}
				}
				
			}
		}
	}

	cout << answer;

	return 0;

}


