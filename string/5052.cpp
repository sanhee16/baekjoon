#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <array>
#include <unordered_map>
using namespace std;
struct Trie {
	bool fin;
	Trie* next[10];
	Trie() {
		fin = false;
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < sizeof(next); i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			fin = true;
			return;
		}
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) {
				//cout << cur << endl;
				next[cur] = new Trie();
			}
			next[cur]->insert(key + 1);
		}
	}
	int find(const char* key, int cnt) {
		if (fin == true && cnt == 0) {
			// mine : yes
			return 2;
		}
		if (cnt == 0 || fin == true) {
			//find -> NO 
			return 0;
		}
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) {
				// no key
				return 1;
			}
			else {
				return next[cur]->find(key + 1, cnt-1);
			}
		}	
	}
};
void solution() {
	string ans = "?";
	int t, n;
	cin >> t;
	for (int aa = 0; aa < t; aa++) {
		cin >> n;
		Trie* tr = new Trie();
		vector<string> inp_vec;
		for (int i = 0; i < n; i++) {
			string inp;
			cin >> inp;
			inp_vec.push_back(inp);
			const char* key = inp.c_str();
			tr->insert(key);
		}
		for (int i = 0; i < n; i++) {
			string s = inp_vec[i];
			const char* str = s.c_str();
			int cnt = s.length();
			int ret = tr->find(str, cnt);
			if (ret == 1) {
				
				ans = "YES";
				continue;
			}
			else if (ret == 0) {
				ans = "NO";
				break;
			}
			else if (ret == 2) {
				ans = "YES";

			}
		}

		inp_vec.clear();
	
		cout << ans << endl;
	}

	return ;
}
int main() {
	solution();
	return 0;
}
