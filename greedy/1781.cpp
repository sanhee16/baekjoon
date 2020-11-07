#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;


int main() {
	int n, a, b, answer = 0;
	map<int, vector<int>> m;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m[a].push_back(b);
	}
	map<int, vector<int>>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		sort(iter->second.begin(), iter->second.end(),greater<int>());
	}
	int deadline_idx = 0;
	for (int cur_time = n; cur_time > 0; cur_time--) {
		if (m[cur_time].empty() == false) {
			for (int i = 0; i < m[cur_time].size(); i++) {
				pq.push(m[cur_time][i]);
			}
		}
		if (pq.empty() == false) {
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;

}

