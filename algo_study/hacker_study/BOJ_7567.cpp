#include <iostream>
#include <string>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string bowl;
    cin >> bowl;
    int count = 5; //기본 5로 잡음
    for(int i=0; i<bowl.length(); i++){
        if (i ==0) count += 5; //시작지점일때 +5해서 10
        else if (bowl[i-1] != bowl[i]) count += 10; // ()가 만들어지면 +10
        else count +=5; //그 외에 +5
    }

    cout<< count;

}