#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void){

    string text;
    cin >> text;
    int current = 1;

    int result = 0;

    for(int i=0; i<text.size(); i++){
        if(text[i] == '(') {
            current *= 2;
        } else if (text[i] == '['){
            current *= 3;
        } else if (text[i] == ')'){
            if (text[i-1] == '('){
                result += current;
            }
            current /= 2;

        } else if (text[i] == ']'){
            if (text[i-1] == '['){
                result += current;
            }
            current /= 3;
        } 
    }
    cout<<result;
}