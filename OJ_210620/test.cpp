#include<iostream>
using namespace std;

//反转字符串II
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//这里让i每次移动2K个就达到了每隔2K的目的
		{
			//在本题中可以发现小于2K但大于或者等于K，和大于2K用的代码是一样的，所以这里条件直接写成 如果剩余字符大于K
			if (i + k <= s.size())
			{
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//如果剩余字符少于k个，将剩余字符全反转
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;

	}
};

//反转字符串中的单词III
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
			//让i跳过空格
			while (i < length && s[i] == ' ')
			{
				++i;
			}

		}
		return s;

	}
};