#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
vector<pair<int,int>> homework;
vector<pair<int,int>> completion;

//homework는 마감일 오름차순
//completion은 점수순 오름차순
bool compareByTime(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int d, w;
    while(N--){
        cin >> d >> w;
        homework.push_back({w, d});
    }
    sort(homework.begin(), homework.end(), compareByTime);
    int cur = 1;
    for(auto h: homework){
        if (cur <= h.second){ //들어갈 수 있으면
            completion.push_back({h.first, h.second});
            cur++;
            sort(completion.begin(), completion.end());
        } else { //못 들어가면 교체할 수 있는 것 찾아봄
            for(int i=0; i<completion.size(); i++){
                if(h.first > completion[i].first){                    
                    completion[i].first = h.first;
                    completion[i].second = h.second;
                    sort(completion.begin(), completion.end());
                    break;
                }
            }
        }

    }


    int ans = 0;
    for(auto c: completion) ans += c.first;
    cout<<ans;

}
