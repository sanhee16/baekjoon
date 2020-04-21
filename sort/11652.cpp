#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

#include <array>
#include <queue>
#include <stack>
#include <vector>


using namespace std;

int main(){

        vector<long long> vec;
        int N=0;
        cin >> N;
        long long num = 0;
        for(int i=0;i<N;i++){
                cin >> num;
                vec.push_back(num);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());

        pair<int,long long> most = {0,0};
        int count = 0;
        long long before = vec[0];
        for(int i=0;i<N;i++){
                if(vec[i]==before){
                        count++;
                }else{
                        if(count >= most.first){
                                most.first = count;
                                most.second = before;
                        }
                        count = 1;
                        before = vec[i];
                }
        }
        if(count >= most.first){
                most.first = count;
                most.second = before;
        }


        cout << most.second << endl;
        return 0;

}
