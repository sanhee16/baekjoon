#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <array>
#include <queue>

using namespace std;

int main(){

    string N;
    cin >> N;

    int arr[10] = {0};
    for(int i=0;i< N.length();i++){
        arr[i] = stoi(N.substr(i,1));
    }
    sort(arr,arr+N.length(),greater<int>());
    for(int i=0;i< N.length();i++){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
