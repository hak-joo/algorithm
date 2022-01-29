#include <iostream>
#include <vector>

using namespace std;

int bg, ed;
vector<bool> arr(1000005, true);

int main(void){
    cin >> bg >> ed;
    arr[1] = false;
    for(int i=bg; i <= ed; i++){
        if(arr[i] == false) continue;
        
        for(int j=2; j*j<=i; j++)
            {
                if(i % j ==0) arr[i] = false;
            }
        for(int k =i+i; k <= ed; k+=i)
            arr[k] = false;
    }

    for(int i= bg; i<=ed; i++)
        if(arr[i]) cout<<i<<"\n";
}