#include <iostream>
using namespace std;

void make_apart(int a, int b);
int apart[15][15];

int main() {

	int k;
	int n;
	int T;//testcase
	cin >> T;
	int* result = new int[T];
	int result_count = 0;
	for (int z = 0; z < T; z++) {
		cin >> k >> n;
	
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				apart[i][j] = 0;
				if (i == 0) {
					apart[i][j] = j;
				}
			}
		}
		for (int j = 1; j < n+1; j++) {
			if (apart[k][j]==0) {
				make_apart(k, j);
			}
		}
		result[result_count] = apart[k][n];
		result_count++;

	}
	for (int x = 0; x < T; x++) {
		cout << result[x] << endl;
	}
	return 0;
}

void make_apart(int a, int b) {

	for (int i = 1; i < a + 1; i++) {
		for (int j = 1; j < b + 1; j++) {
			if (apart[i][j] == 0) {
				if (apart[i - 1][j] == 0) {
					make_apart(i - 1, j);
				}
				for (int x = 1; x < b + 1; x++) {
					apart[i][j] += apart[i - 1][x];
				}
			}
		}
	}
}
