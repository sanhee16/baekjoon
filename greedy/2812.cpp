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
	int n, k;
	vector<pair<int, int > > v;
	deque<int> dq;

	string str;
	cin >> n >> k;
	cin >> str;
	int ksave = k;
	for (int i = 0; i < n; i++) {
		int val = atoi(str.substr(i, 1).c_str());

		while (dq.empty() == false && dq.back() < val && k>0) {
			dq.pop_back();
			k--;
		}
		dq.push_back(val);
		
		
	}
	for (int i = 0; i < n - ksave; i++) {
		cout << dq.front();
		dq.pop_front();
	}

	return 0;

}
