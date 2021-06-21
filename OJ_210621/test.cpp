#include<iostream>
using namespace std;

//左旋转字符串
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int start = 0;
		int end = 0;
		//翻转前半段
		while (end < n)
		{
			if (end == n - 1)
			{
				reverse(s.begin(), s.begin() + end + 1);
			}
			++end;
		}
		start = end;
		//翻转后半段
		while (end < s.size())
		{
			if (end == s.size() - 1)
			{
				reverse(s.begin() + start, s.begin() + end + 1);
			}
			++end;
		}

		//整个翻转
		reverse(s.begin(), s.end());

		return s;

	}
};

int main()
{
	
	return 0;
}