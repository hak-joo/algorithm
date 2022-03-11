#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string yeondu;
vector<pair<int, string>> team;
int N;
int L, O, V, E;

void calcScore(){
    int base[4] = {0};
    int sum[4] = {0};
    for(int i=0; i<yeondu.length(); i++){
        if(yeondu[i] == 'L') base[0]++;
        else if (yeondu[i] == 'O') base[1]++;
        else if (yeondu[i] =='V') base[2]++;
        else if (yeondu[i] == 'E') base[3]++;
    }
    for(int i=0; i<team.size(); i++){
        L = base[0]; O = base[1]; V = base[2]; E = base[3];
        for(auto c: team[i].second){
            if(c == 'L') L++;
            else if (c == 'O') O++;
            else if (c =='V') V++;
            else if (c == 'E') E++;
        }
        team[i].first = ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E))%100;
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> yeondu;
    cin >> N;

    string team_name;
    while(N--){
        cin >> team_name;
        team.push_back({-1,team_name});
    }
    calcScore();

    int maxIdx = 0;
    int maxValue = team[0].first;
    for(int i=0; i<team.size(); i++){
        if(maxValue < team[i].first){
            maxValue = team[i].first;
            maxIdx = i;
        } else if (maxValue == team[i].first){
            if(team[i].second.compare(team[maxIdx].second) < 0) {
                maxValue = team[i].first;
                maxIdx = i;
            }
        }
    }
    cout<<team[maxIdx].second;


}