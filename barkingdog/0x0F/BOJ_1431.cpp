#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int n;
string arr[51];

bool cmp(string A, string B){
    int sumA = 0;
    int sumB = 0;
    if(A.size() < B.size())
        return true;
    else if (A.size () == B.size()){
        for(int i=0; i<A.size(); i++){
            if('0' <= A[i] && A[i] <= '9')
                sumA += A[i];
            if('0' <= B[i] && B[i] <= '9')
                sumB += B[i]; 
        }
        if (sumA < sumB) return true;
        else if (sumA > sumB) return false;
        else{
            if (A < B) return true;
            else return false;
        }
    } else{
        return false;
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}