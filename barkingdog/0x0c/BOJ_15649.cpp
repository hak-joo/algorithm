#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool unused[10];

void func(int k);

int main(void){

    cin >> N >> M;
    func(0);

}

void func(int k){
    if(k == M){
        for(int i=0; i<M; i++){
            cout<< arr[i]<< " ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1; i<=N; i++){
        if(!unused[i]){
            arr[k] = i;
            unused[i] = true;
            func(k+1);
            unused[i] = false;
        }
        
    }

}