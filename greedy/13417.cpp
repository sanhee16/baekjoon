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

	int t, n;
	cin >> t;
	for (int loop = 0; loop < t; loop++) {
		cin >> n;
		char ch;
		deque<char>dq;
		for (int i = 0; i < n; i++) {
			cin >> ch;
			if (dq.empty() == true)
				dq.push_back(ch);
			else {
				if (dq.front() < ch)
					dq.push_back(ch);
				else
					dq.push_front(ch);
			}
		}
		string ans;
		for (int i = 0; i < n; i++) {
			ans += dq.front();
			dq.pop_front();
		}
		cout << ans << endl;

	}

	return 0;

}


