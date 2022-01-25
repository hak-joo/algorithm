#include <iostream>
using namespace std;


int A,B,C;
int cnt[10];
int main(void){
    cin >> A >> B >> C;
    int mul = A*B*C;

    while(mul != 0){
        cnt[mul%10]++;
        mul /= 10;
    } 
    for(int i=0; i<10; i++)
        cout<<cnt[i]<<"\n";
}