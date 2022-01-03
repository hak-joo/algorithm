#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n;
    cin >>n;
    stack<int> S;
    string op;

    while(n--){   
        cin>>op;
        if(op == "push"){
            int input;
            cin>>input;
            S.push(input);
        }
        else if (op == "top") {
            if(!S.empty()) cout<< S.top() <<"\n";
            else cout<<"-1\n";
        }
        else if (op == "size") cout<<S.size()<<"\n";
        else if (op == "empty") cout <<S.empty()<<"\n";
        else {
            if(!S.empty()){
                cout << S.top()<<"\n";
                S.pop();
            }
            else cout<<"-1\n";
        }
    }
}