
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <array>
#include <queue>

using namespace std;

// 1260

void dfs();
void bfs();
static int vertex, edge, start;
static int** arr;
static int overlap;

int main() {
	cin >> vertex >> edge >> start;
	//2차원 배열 동적할당
	arr = new int* [vertex]; 
	
	for (int i = 0; i < vertex; i++) {
		arr[i] = new int[vertex];
		fill(arr[i],arr[i]+vertex,0);
	}
	int edge1 = 0; 
	int edge2 = 0;
	
	for (int i = 0 ; i < edge ; i++) {
		cin >> edge1 >> edge2;
		if (arr[edge1 - 1][edge2 - 1] == 1) {
			overlap++;
		}
		else {
			arr[edge1 - 1][edge2 - 1] = 1;
			arr[edge2 - 1][edge1 - 1] = 1;
		}
	}
	//dfs
	dfs();
	cout << endl;
	//bfs
	bfs();
	return 0;

}


void dfs() {
	stack<int> s;
	long* visited = new long[vertex];
	fill(visited, visited + vertex, 0);
	s.push(start);
	int u = 0;
	int v = 0;
	int visit_count = 0;

	while (true) {
		u = s.top();
		s.pop();
		for (int v = vertex; v > -1; v--) {
			if (arr[u - 1][v - 1] == 1 && visited[v - 1] == 0) {
				s.push(v);
			}
		}
		if (visited[u - 1] == 0) {
			visited[u - 1] = 1;
			cout << u ;
			visit_count++;
			if (s.empty() == true)
				break;
			if (visit_count == vertex) {
				break;
			}
			cout << " ";
		}
	}
	delete[] visited;
	return;
}


void bfs() {
	queue<int> q;
	int* visited = new int[vertex];
	fill(visited, visited + vertex, 0);
	int visit_count = 0;

	q.push(start);
	int u;
	int v;
	while (true) {
		u = q.front();
		q.pop();
		for (int v = 1; v < vertex + 1; v++) {
			if (visited[v - 1] == 0 && arr[u - 1][v - 1] == 1) {
				q.push(v);
			}
		}
		if (visited[u - 1] == 0) {
			visited[u - 1] = 1;
			visit_count++;
			cout << u;
			if (q.empty() == true)
				break;
			if (visit_count == vertex)
				break;
			cout << " ";
		}
		
	}
	delete[] visited;
	return;

}
