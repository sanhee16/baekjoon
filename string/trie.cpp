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
	Trie* next[26];
	Trie() {
		fin = false;
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		cout << "delete " << endl;
		for (int i = 0; i < 26; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	void insert(const char* key) {
		cout << "insert key : " << key << endl;
		if (*key == '\0') {
			fin = true;
			cout << "end " << endl;
			return;
		}
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL) {
				next[curr] = new Trie();
			}
			next[curr]->insert(key + 1);
			return;
		}
	}

	Trie* find(const char* key) {
		if (fin == true) {
			//cout << "find : " << key << endl;
			return this;
		}
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL) {
				cout << "nope " << curr << endl;
				return NULL;
			}
			return next[curr]->find(key + 1);
		}
	}
};

void trie() {
	//cout << "hello world!" << endl;
	const char* str = "abdadc";
	Trie* test = new Trie();
	test->insert(str);
	Trie* ans = new Trie();
	ans = test->find("abdadc");
	ans = test->find("000");


	return;
}
