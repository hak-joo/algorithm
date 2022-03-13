#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<string> v;
vector<string> result;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    string temp;
    for(int i=0; i<N+M; i++){
        cin >> temp;
        v.push_back(temp);     
    }
    sort(v.begin(), v.end());
    for(int i=1; i<N+M; i++){
        if(v[i] == v[i-1]) result.push_back(v[i]);
    }
    cout<<result.size()<<"\n";
    for(auto s: result) cout<<s<<"\n";
}