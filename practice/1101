#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int loop;
	cin >> loop;
	int* answer;
	answer = new int[loop];

	for (int a = 0; a < loop; a++) {
		answer[a] = 0;
	}
	for(int a = 0;a<loop;a++){
		int x;
		int y;
		cin >> x >> y;
		int distance = y - x - 1;

		int half = int(distance / 2);
		int sum = 0;
		int i = 0;
		while (true) {
			i++;
			sum += i;
			if (sum > half) {
				sum -= i;
				i--;
				break;
			}
		}
		int rest = distance - sum;
		answer[a] += i;

		sum = 0;
		i = 0;
		int j = 1;
		int sum_j = 0;
		while (true) {
			i++;
			j++;
			sum += i;
			sum_j += j;
			if (sum > rest) {
				sum -= i;
				i--;
				sum_j -= j;
				j--;
				break;
			}
		}
		if (i < j) {
			answer[a] += j;

		}else{
			answer[a] += i;
		}
	}
	for (int a = 0; a < loop; a++) {
		cout << answer[a] << endl;
	}
	delete answer;

	

	return 0;
}
