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

	int k, n;
	cin >> k;
	for (int loop = 0; loop < k; loop++) {
		cin >> n;
		int answer = 0;
		string str1, str2;
		int cntB = 0, cntW = 0;
		cin >> str1 >> str2;
		for (int i = 0; i < n; i++) {
			if (str1[i] != str2[i]) {
				if (str1[i] == 'W')
					cntW++; // 2
				else
					cntB++; // 1
			}
		}
		answer = cntW + cntB - min(cntW, cntB);
		cout << answer << endl;
	}

	return 0;

}


