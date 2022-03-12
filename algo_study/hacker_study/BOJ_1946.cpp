#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> recruits;
int N;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int recruit_num, cnt;
    while(N--){
        cnt = 1;
        cin >> recruit_num;
        for(int i=0; i<recruit_num; i++){
            int fst, scd;
            cin >> fst >> scd;
            recruits.push_back({fst, scd});
        }
        sort(recruits.begin(), recruits.end());

        int mn = recruits[0].second;
        for(int i=1; i<recruits.size(); i++){
            if(recruits[i].second < mn){
                cnt++;
                mn = recruits[i].second;
            }
        }
        cout << cnt<<"\n";
        recruits.clear();
    }
}
