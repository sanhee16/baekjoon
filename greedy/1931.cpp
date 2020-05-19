#include <iterator>
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

bool cmp(pair<int, int> a, pair<int, int> b){
        if(a.second < b.second)
                return true;
        else if(a.second > b.second)
                return false;
        else if(a.second == b.second){
                if(a.first < b.first)
                        return true;
                else
                        return false;
        }


}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<pair<int,int>> vec;
        int N = 0;
        cin >> N;
        int num1,num2=0;
        for(int i=0;i<N;i++){
                cin >> num1 >> num2;
                vec.push_back(make_pair(num1,num2));
        }

        sort(vec.begin(),vec.end(),cmp);

        int num=0;
        int last = 0;
        for(int i=0;i<N;i++){
                if(vec[i].first >= last){
                        num++;
                        last = vec[i].second;
                }
        }

        cout << num << endl;
        return 0;
}
