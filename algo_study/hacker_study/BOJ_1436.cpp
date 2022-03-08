#include <iostream>
#include <string>
using namespace std;

int N;
int result = 666;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    string temp;
    while(1){
        temp = to_string(result); //문자열로 변환
        if(temp.find("666") != string::npos) N--; //666들어가는지 체크
        if(N == 0) break;
        result++;
    }
    cout<< result;

}