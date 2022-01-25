#include <iostream>
using namespace std;

int n;
int cnt = 1;

int main(void){
    cin >> n;
    int result = ((n%10) + (n/10)) %10 + (n%10 * 10);
    while(1){
        if(result == n) break;
        result = ((result%10) + (result/10)) %10 + (result%10 * 10);
        cnt ++;
    }
    cout<<cnt;
}