#include <iostream>
#include <string>
using namespace std;

int freq[26];
int main(){
    string s;
    cin>> s;

    for(auto c : s){
        freq[c-'a']++;
    }
    for (int i=0; i<26; i++){
        cout<< freq[i]<< " ";
    }
}