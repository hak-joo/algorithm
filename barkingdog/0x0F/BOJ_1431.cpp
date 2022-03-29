#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int n;
string arr[51];

int sum(string a){
    int ret = 0;
    for(int i=0; i<a.length(); i++){
        if((a[i]-'0') >= 1 && (a[i] - '0') <= 9 ) ret+= a[i]-'0';
    }
    return ret;
}

bool cmp(string A, string B){
    if(A.size() != B.size()) return A.size() < B.size();
    else{
        int aSize = sum(A);
        int bSize = sum(B);
        if(aSize != bSize){
            return aSize < bSize;
        } else return A<B;
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
}