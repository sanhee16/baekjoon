#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
using namespace std;

class Heap {
public:
    vector<int> heap;
    int heap_cnt;
    Heap() {
        heap.push_back(1e9);
        heap_cnt = 0;
    }
    void pushBig(int data);
    int popBig();
    void pushSmall(int data);
    int popSmall();
    int cntReturn();
    int top();
};
int Heap::cntReturn() {
    return heap_cnt;
}
void Heap::pushBig(int data) {

    // 힙의 가장 끝에 데이터 추가
    //heap[++heap_cnt] = data;
    heap.push_back(data);
    heap_cnt++;
    // 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 올리는 부분
    int child = heap_cnt;
    int parent = child / 2;
    while (child > 1 && heap[parent] < heap[child]) {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }

}
int Heap::popBig() {

    // 힙의 가장 첫번째 원소를 반환
    // 힙의 가장 앞만 보고 있다!
    int result = heap[1];

    // 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고
    // 가장 끝은 이제 쓰지 않을 예정이니 heap_count를 내려준다.
    swap(heap[1], heap[heap_cnt]);
    heap_cnt--;

    // 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_cnt) {
        child = (heap[child] < heap[child + 1]) ? child : child + 1;
    }

    while (child <= heap_cnt && heap[parent] < heap[child]) {
        swap(heap[parent], heap[child]);

        parent = child;
        child = child * 2;
        if (child + 1 <= heap_cnt) {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }
    }

    return result;
}
void Heap::pushSmall(int data) {

    // 힙의 가장 끝에 데이터 추가
    //heap[++heap_cnt] = data;
    heap.push_back(data);
    heap_cnt++;
    // 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 올리는 부분
    int child = heap_cnt;
    int parent = child / 2;
    while (child > 1 && heap[parent] >  heap[child]) {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }

}
int Heap::popSmall() {

    // 힙의 가장 첫번째 원소를 반환
    // 힙의 가장 앞만 보고 있다!
    int result = heap[1];

    // 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고
    // 가장 끝은 이제 쓰지 않을 예정이니 heap_count를 내려준다.
    swap(heap[1], heap[heap_cnt]);
    heap_cnt--;

    // 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_cnt) {
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }

    while (child <= heap_cnt && heap[parent] > heap[child]) {
        swap(heap[parent], heap[child]);

        parent = child;
        child = child * 2;
        if (child + 1 <= heap_cnt) {
            child = (heap[child] < heap[child + 1]) ? child : child + 1;
        }
    }

    return result;
}
int Heap::top() {
    return heap[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Heap h = Heap();
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        if (pq.size() == n) {
            if (tmp > pq.top()) {
                pq.pop();
                pq.push(tmp);
            }
        }
        else {
            pq.push(tmp);
        }
    }

    ans = pq.top();
    cout << ans;

    return 0;
} 
