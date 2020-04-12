//https://www.acmicpc.net/problem/3986
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


int main() {
	int N;
	cin >> N;
	string word;
	int good_word = 0;
	for (int i = 0; i < N; i++) {
		cin >> word;
		stack<int> s;
		for (int j = 0; j < word.size(); j++) {
			if (s.empty() == true) {
				s.push(word[j]);
			}
			else {
				if (s.top() == word[j]) {
					s.pop();
				}
				else {
					s.push(word[j]);
				}
			}
		}
		if (s.empty() == true) {
			good_word++;
		}
	}
	cout << good_word << endl;




	return 0;
}

