#include <string>
#include <vector>
#include <iostream>
using namespace std;

//扑克牌的大小

#define PrintS1 {cout << s1 << endl;return 0;}
#define PrintS2 {cout << s2 << endl;return 0;}
int count(string & str) {
	int n = 0;
	string::size_type  i = 0, k = 0;
	while ((k = str.find(' ', i)) != string::npos) {
		n++; i = k + 1;
	}
	return n;
}
int main() {
	string input;
	getline(cin, input);
	string s1, s2;
	int t = input.find('-');
	s1 = input.substr(0, t);
	s2 = input.substr(t + 1);
	int n1 = count(s1);
	int n2 = count(s2);
	string POKER = "345678910JQKA2jokerJOKER";
	vector<string> MAX = { "joker JOKER", "JOKER joker" };
	if (s1 == MAX[0] || s1 == MAX[1]) PrintS1
		if (s2 == MAX[0] || s2 == MAX[1]) PrintS2
			if (n1 == n2) {
				string f1, f2;
				string::size_type k = s1.find(' ');
				f1 = s1.substr(0, k);
				k = s2.find(' ');
				f2 = s2.substr(0, k);
				if (POKER.find(f1) > POKER.find(f2))PrintS1
					PrintS2
			}
	if (n1 == 3 && n2 != 3) PrintS1
		if (n2 == 3 && n1 != 3) PrintS2
			cout << "ERROR" << endl;
}