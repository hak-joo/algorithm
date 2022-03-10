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