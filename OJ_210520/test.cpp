
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//MP3¹â±êÎ»ÖÃ
string s;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		cin >> s;
		int cur_head = 1, cur_pos = 0;
		if (n <= 4) {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					cur_pos = (cur_pos + n - 1) % n;
				}
				else {
					cur_pos = (cur_pos + 1) % n;
				}
			}
		}
		else {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					if (cur_head == 1 && cur_pos == 0) {
						cur_head = n - 3;
						cur_pos = 3;
					}
					else {
						if (cur_pos > 0) {
							cur_pos--;
						}
						else {
							cur_head--;
						}
					}
				}
				else {
					if (cur_head == n - 3 && cur_pos == 3) {
						cur_head = 1;
						cur_pos = 0;
					}
					else {
						if (cur_pos < 3) {
							cur_pos++;
						}
						else {
							cur_head++;
						}
					}
				}
			}
		}
		for (int i = 0; i < min(n, 4); i++) {
			if (i) {
				printf(" ");
			}
			printf("%d", cur_head + i);
		}
		printf("\n%d\n", cur_head + cur_pos);
	}
	return 0;
}