#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
set<string> company;


int N;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    string name, status;
    while(N--){
        cin >> name >> status;
        if(status == "enter") company.insert(name);
        else company.erase(name);
    }

    for(auto it = company.rbegin(); it != company.rend(); it++){
        cout<< *it<<"\n";
    }
}