#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        int start, end;
        cin >> start  >> end;
        v.push_back({end, start});
    }
    sort(v.begin(), v.end());
    
    int endTime = v[0].first;
    int res = 1;
    
    for(int i=1; i<v.size(); i++){
        if(endTime <= v[i].second){
            res++;
            endTime = v[i].first;
        }       
    }
    cout << res;

}