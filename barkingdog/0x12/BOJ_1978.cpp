#include <iostream>

using namespace std;

int n;
int arr[105];
int cnt = 0;
int main(void){
    cin >> n;
    cnt = n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++){
        if (arr[i] <2) cnt--;
        else{
            for(int j=2; j*j<=arr[i]; j++){
                if(arr[i]%j ==0){
                    cnt--;
                    break;
                }
            }
        }
        
    }    
    cout<<cnt;
}