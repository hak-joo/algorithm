// #include <iostream>
// #include <list>

// using namespace std;

// int N;

// int main(void){
//     cin.tie(0); cout.tie(0);
//     ios::sync_with_stdio(0);

//     cin >> N;
//     list<char> l;
//     string input;
//     list<char>::iterator iter;
//     while(N--){
//         cin >> input;
//         l.clear();
//         iter = l.begin();

//         for(int i=0; i<input.length(); i++){
//             if(input[i] == '<' && iter!=l.begin()) iter--;
//             else if(input[i] == '>' && iter != l.end()) iter++;
//             else if(input[i] == '-' && iter != l.begin()) l.erase(--iter);
//             else if(input[i] != '-' && input[i] != '<' && input[i] != '>'){
//                 l.insert(iter, input[i]);
//             }
//         }
//         for(iter =l.begin(); iter!=l.end(); iter++) cout<< *iter;
//         cout<<'\n';
//     }
// }

#include <iostream>
#include <list>
using namespace std;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int T;
	list<char> l;
	list<char>::iterator iter;
	string input;
	cin >> T;
 
	for (int i = 0; i < T; i++) {
		cin >> input;
		l.clear();
		iter = l.begin();
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '<' && iter != l.begin()) iter--;
			else if (input[j] == '>' && iter != l.end()) iter++;
			else if (input[j] == '-' && iter != l.begin()) iter = l.erase(--iter);
			else if (input[j] != '<' && input[j] != '>' && input[j] != '-') l.insert(iter, input[j]);
		}
		for (iter = l.begin(); iter != l.end(); iter++) cout << *iter;
		cout << '\n';
	}
 
	return 0;
}