#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
vector<int> v;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) v.push_back(i+1);
    
    cout<<"<";
    while(1){
        for(int i=0; i<K-1; i++){
           auto temp = v.front();
           v.erase(v.begin());
           v.push_back(temp);
        }
        auto frt = v.front();
        v.erase(v.begin());
        cout << frt;
        if(v.size() == 0) break;
        else cout<<", ";
    }
    cout<<">";

}

