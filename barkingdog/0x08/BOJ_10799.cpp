#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main (void){
        
    string text;
    cin>>text;
    int count = 0; // 쇠 막대기의 개수
    int result = 0; // 조각난 개수

    for (int i=0; i<text.size(); i++){
        if (text[i] == '('){
            count++;
        }
        else if (text[i] == ')'){
            if(text[i-1] == '('){ //razer
                count--;
                result +=count;
            } else{
                result++;
                count--;
            }
        }
    }
    cout<<result;
}