#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<string, int>> book;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    string title;
    bool found = false;

    while(N--){
        found = false;
        cin >> title;
        for(int i=0; i<book.size(); i++){
            if(book[i].first == title){ //이미 값이 존재할 때 pair 카운트 값을 늘려줌
                book[i].second++;
                found = true;
                break;
            }
        }
        if(!found){ // 찾지 못하였을 때 새로 만들어서 카운트는 1로 초기화
            pair<string, int> t;
            t.first = title;
            t.second = 1;
            book.push_back(t);
        }
    }

    int maxIdx = 0;
    int max = book[0].second;
    for(int i=0; i<book.size(); i++){
        if(max <= book[i].second){
            if (max < book[i].second){ //클 때 change
                max = book[i].second;
                maxIdx = i;
            } else {
                if(book[i].first.compare(book[maxIdx].first) < 0) maxIdx = i; //사전식 비교
            }
        }
    }
    cout << book[maxIdx].first; //최종 max index의 string 값 출력
}