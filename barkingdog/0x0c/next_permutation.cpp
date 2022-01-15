#include <iostream>
#include <algorithm>
using namespace std;

int a[4] = {0,0,1,1};


int main(void){
    do{
        for(int i=0; i<4; i++){
            if(a[i] == 0) cout <<i ;
        }
        cout << "\n";
    } while(next_permutation(a, a+4));
    
}