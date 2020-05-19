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

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N, K;
        vector<int> money;
        cin >> N >> K;

        int a;
        for(int i=0;i<N;i++){
                cin >> a;
                money.push_back(a);
        }
        sort(money.begin(),money.end(),greater<int>());
        int num = 0;
        int order_money;
        int order = 0;
        int left_money = K;
        while(true){
                order_money = money[order];
                order++;
                if(order_money > left_money){
                        continue;
                }

                num += left_money / order_money;
                left_money -= (left_money/order_money)*order_money;

                if(left_money==0)
                        break;

        }
        cout << num << endl;
        return 0;
}
