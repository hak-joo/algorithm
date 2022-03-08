#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;
string func; //수행할 함수
string ary; // 배열
int aryN; // 배열 개수
deque<string> DQ;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string temp = "";
    cin >> T;
    bool err;
    while(T--){
        err = false;
        cin >> func >> aryN >> ary;

        for(int i=0; i<ary.length(); i++){ //push
            if(ary[i] != '[' && ary[i] != ']' && ary[i] != ',') temp += ary[i];
            else{
                if(temp.size()!=0) {
                    DQ.push_back(temp);
                    temp = "";
                }
            }
        }
        int rCount = 0;
        for(int i=0; i<func.length(); i++){ //함수별 연산
            if(func[i] == 'R')rCount++;
            else if (func[i] == 'D'){
                if(DQ.size() ==0) {
                    cout<< "error\n";
                    err = true;
                    break;
                } else {
                    if(rCount %2 ==0) DQ.pop_front(); //회전이 짝수번일 때, 앞에서 삭제
                    else DQ.pop_back(); //회전이 홀수번일 때, 뒤에서 삭제
                }
            }
        }
        int qSize = DQ.size();
        if(qSize == 0 && !err) cout<<"[]\n";
        else if (err) {}
        else{
            cout<<"[";
            while(DQ.size()){
                if(rCount %2 ==0){
                    cout<<DQ.front();
                    DQ.pop_front();
                } else{
                    cout<< DQ.back();
                    DQ.pop_back();
                }
                if(DQ.size() ==0) cout<<"]\n";
                else cout<<",";
            }
        }
    }
}