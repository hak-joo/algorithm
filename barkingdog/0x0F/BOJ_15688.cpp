#include <iostream>
#include <cmath>

using namespace std;

int N;
int freq[2000001];
int num;
int main(void){

    cin>> N;
    for(int i=0; i<N; i++){
        cin >> num;
        freq[num + 1000000]++;
    }

    for(int i=0; i<= 2000000; i++){
        while(freq[i]--){
            cout<< i - 1000000<<"\n";
        }
    }


}