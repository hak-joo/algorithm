#include <queue>
#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >>n;
    queue<int> Q;
    string op;
    while(n--){
        cin>> op;
        if (op == "push"){
            int input;
            cin>>input;
            Q.push(input);
        } else if (op == "pop"){
            if(!Q.empty()){
                cout << Q.front()<<"\n";
                Q.pop();
            } else cout<<"-1\n";
        } else if (op == "size"){
            cout << Q.size() << "\n";
        } else if (op == "front"){
            if(!Q.empty()) cout <<Q.front() << "\n";
            else cout<<"-1\n";
        } else if (op == "empty") cout<<Q.empty()<<"\n";
        else { // back
            if(!Q.empty()) cout<<Q.back() <<"\n";
            else cout<<"-1\n";
        }
    }
}