#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int M, N;

set<int> s;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int input;
    while(N--){
        cin >> input;
        s.insert(input);
    }
    cin >> M;
    while(M--){
        cin >> input;
        cout << (s.find(input) != s.end()) << "\n";
    }

}