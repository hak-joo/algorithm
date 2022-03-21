#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> minQ;
priority_queue<int> maxQ;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int input;
    
    while(N--){
        cin >> input;
        if(minQ.size() >= maxQ.size()) maxQ.push(-1 * input); 
        else minQ.push(input);
        
        if(minQ.size() > 0 && maxQ.size() > 0 && minQ.top() > maxQ.top() * -1 ){
            int mn = minQ.top(); minQ.pop();
            int mx = maxQ.top(); maxQ.pop();       
            minQ.push(-1 * mx); maxQ.push(-1 * mn); //swap
        }
        if(minQ.size() == 0) cout << -1 * maxQ.top()<<"\n";
        else if(minQ.size() == maxQ.size()) cout << minQ.top() << "\n";
        else cout << -1 * maxQ.top() << "\n";
    }
}