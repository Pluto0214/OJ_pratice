#include<iostream>
using namespace std;

//��ת�ַ���II
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//������iÿ���ƶ�2K���ʹﵽ��ÿ��2K��Ŀ��
		{
			//�ڱ����п��Է���С��2K�����ڻ��ߵ���K���ʹ���2K�õĴ�����һ���ģ�������������ֱ��д�� ���ʣ���ַ�����K
			if (i + k <= s.size())
			{
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//���ʣ���ַ�����k������ʣ���ַ�ȫ��ת
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;

	}
};

//��ת�ַ����еĵ���III
class Solution {
public:
	string reverseWords(string s) {
		int i = 0;
		int length = s.size();
		while (i < length)
		{
			int start = i;
			while (i < length && s[i] != ' ')
			{
				++i;
			}
			int left = start, right = i - 1;
			while (left < right)
			{
				swap(s[left], s[right]);
				left++;
				right--;
			}
			//��i�����ո�
			while (i < length && s[i] == ' ')
			{
				++i;
			}

		}
		return s;

	}
};