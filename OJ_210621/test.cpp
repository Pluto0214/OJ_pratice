#include<iostream>
using namespace std;

//����ת�ַ���
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int start = 0;
		int end = 0;
		//��תǰ���
		while (end < n)
		{
			if (end == n - 1)
			{
				reverse(s.begin(), s.begin() + end + 1);
			}
			++end;
		}
		start = end;
		//��ת����
		while (end < s.size())
		{
			if (end == s.size() - 1)
			{
				reverse(s.begin() + start, s.begin() + end + 1);
			}
			++end;
		}

		//������ת
		reverse(s.begin(), s.end());

		return s;

	}
};

int main()
{
	
	return 0;
}