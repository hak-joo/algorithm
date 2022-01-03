#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string text;
    getline(cin, text);
    stack<char> S;
    for (auto c : text){
        if (c == '[' || c == '('){
            S.push(c);
        }

        else if (c == ']'){
            if (!S.empty()){
                if (S.top() == '['){
                    S.pop();
                } else {
                    cout << "no\n";
                    exit(1);
                }    
            } else {
                cout<<"no\n";
                exit(1);
            }
        } else if (c == ')'){
            if(!S.empty()){
                if (S.top() == '(') S.pop();
                else {
                    cout<<"no\n";
                    exit(1);
                }
            }
             else {
                cout<<"no\n";
                exit(0);
            }
        }
    }
    cout<<"yes\n";

}