#include <iostream>
#include <stack>

using namespace std;

stack<int> credit;
int money;
int n;
int cnt = 0;

int main(void){
    int t;
    cin >> n >> money;
    for(int i=0; i<n; i++){
        cin >> t;
        credit.push(t);
    }
    while(!credit.empty() && money>0){
        t = credit.top();
        while(money >= t){
            cnt++;
            money -= t;
        }
        credit.pop();

    }
    cout<< cnt;
}