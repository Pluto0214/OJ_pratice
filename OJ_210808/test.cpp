#include<iostream>
#include<vector>
using namespace std; 

//344.��ת�ַ���
class Solution {
public:
	void reverseString(vector<char>& s) {
		//˫ָ��
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			++left;
			--right;
		}
	}
};

//541.��ת�ַ���II
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//ÿ����i��2k��������ʵ�� ÿ2k���ַ�...��
		{
			//ʣ���ַ�����k�ʹ���2k�������һ����
			if (s.size() - i >= k)
			{
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else//��ʣ���ַ�ȫ����ת
			{
				reverse(s.begin() + i, s.end());
			}
		}
		return s;

	}
};

int main()
{
	
	return 0;
}