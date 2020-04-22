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

pair<pair<string,int>,pair<int,int> > student[100000];

bool cmp(pair<pair<string,int>,pair<int,int> > a,
                pair<pair<string,int>,pair<int,int> > b){
        if(a.first.second > b.first.second){
                return true;
        }else if(a.first.second == b.first.second){
                if(a.second.first < b.second.first){
                        return true;
                }else if(a.second.first == b.second.first){
                        if(a.second.second > b.second.second){
                                return true;
                        }else if(a.second.second == b.second.second){
                                if(a.first.first < b.first.first){
                                        return true;
                                }
                        }
                }
        }
        return false;
}

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int N=0;
        cin >> N;
        //int kor,eng,math=0;
        //string name="";
        for(int i=0;i<N;i++){
                cin >> student[i].first.first >> student[i].first.second >> student[i].second.first >> student[i].second.second ;
                //cin>>name>>kor>>eng>>math;
                //student.push_back(make_pair(make_pair(name,kor),make_pair(eng,math)));
        }

        //cout << student[2].first << " " <<  student[2].second.first<< endl;
        sort(student,student+N,cmp);
        for(int i=0;i<N;i++){
                cout << student[i].first.first << "\n";
        }

        return 0;
}
