#include<iostream>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		if (s.size() <= 0)
		{
			return s;
		}
		//1.ɾ������ո�
		//ʹ�ÿ���ָ��
		int fast = 0;
		int slow = 0;
		//ɾ����һ������֮ǰ�Ŀո�
		while (s[fast] == ' ' && fast < s.size())
		{
			++fast;
		}
		//ɾ�������м����Ŀո�
		while (fast < s.size())
		{
			//��������������ո���ɾ��һ��
			if (s[fast] == ' ' && s[fast + 1] == ' ' && fast + 1 < s.size())
			{
				++fast;
			}
			else
			{
				s[slow] = s[fast];
				++slow;
				++fast;
			}
		}
		//ɾ��ĩβ�ո�
		if (s[slow - 1] == ' ' && slow - 1 > 0)
		{
			s.resize(slow - 1);
		}
		else
		{
			s.resize(slow);
		}

		//2.���������ַ���
		reverse(s.begin(), s.end());
		/*for(int left = 0, right = s.size(); left <=right; ++left, --right)
		{
		swap(s[left], s[right]);
		}*/

		//3.���õ���
		for (int i = 0; i < s.size(); ++i)
		{
			int j = i;
			while (s[j] != ' ' && j < s.size())
			{
				++j;
			}
			reverse(s.begin() + i, s.begin() + j);
			i = j;
		}

		return s;

	}
};

int main()
{
	
	return 0;
}