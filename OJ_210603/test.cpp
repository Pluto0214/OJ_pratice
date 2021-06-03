#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, s;
	int count = 0;
	while (cin >> str >> s) {
		count = 0;
		size_t pos = 0;
		while ((pos = str.find(s, pos)) != string::npos) {
			pos += s.size();
			++count;
		}
		cout << count << endl;
	}
	return 0;
}
