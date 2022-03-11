#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> Q;
int N;

int getMax(vector<pair<int,int>> Q);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;

    int Q_num, target, important;
    int max_important;
    while(N--){
        cin >> Q_num >> target;
        for(int i=0; i<Q_num; i++){
            cin >> important;
            Q.push_back({i, important});
        }
        target = Q[target].first;
        int count = 0;
        while(1){
            int mx = getMax(Q); //최대 중요도 값 가져오기
            if(Q[0].second == mx){ //맨 앞 값이 max일 때 (출력)
                count++;
                if(Q[0].first == target) break;
                Q.erase(Q.begin());
               
            } else{
                auto temp = Q.front();
                Q.push_back(temp);
                Q.erase(Q.begin());
            }
        }
        cout << count << "\n";
        Q.clear();
    }
}

int getMax(vector<pair<int,int>> Q){
    int mx = Q[0].second;
    for(int i=0; i<Q.size(); i++){
        if (mx < Q[i].second) mx = Q[i].second;
    }
    return mx;
}