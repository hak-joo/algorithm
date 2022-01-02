#include <iostream>
#include <list>

using namespace std;

int main(){
    string input;
    cin>>input;
    list<char> L;
    for(auto c: input) L.push_back(c);
    auto cursor = L.end();

    int q;
    cin>>q;

    while(q--){
        char op;
        cin>>op;
        if(op == 'P'){
            char add;
            cin>> add;
            L.insert(cursor, add);
        }
        else if (op =='L'){
            if(cursor != L.begin()) cursor--;
        }
        else if (op =='D'){
            if(cursor != L.end()) cursor++;
        }
        else {
            if (cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for(auto c : L) cout<<c;    

    return 0;
}