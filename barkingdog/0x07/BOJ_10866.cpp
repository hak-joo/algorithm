#include <deque>
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    string op;
    deque<int> DQ;
    while(n--){
        cin>>op;
        if (op == "push_back"){
            int input;
            cin >> input;
            DQ.push_back(input);
        } else if (op == "push_front"){
            int input;
            cin >> input;
            DQ.push_front(input);
        } else if (op == "size"){
            cout << DQ.size() << "\n";
        } else if (op == "empty"){
            cout << DQ.empty() << "\n";
        } else if (op == "pop_back"){
            if(!DQ.empty()){
                cout << DQ.back() << "\n";
                DQ.pop_back();
            } else cout << "-1\n";
        } else if (op == "pop_front"){
            if(!DQ.empty()){
                cout << DQ.front() << "\n";
                DQ.pop_front();
            } else cout << "-1\n";
        } else if (op == "front"){
            cout<<DQ.front() << "\n";
        } else if (op == "back"){
            cout<<DQ.back() << "\n";
        }
    }
}