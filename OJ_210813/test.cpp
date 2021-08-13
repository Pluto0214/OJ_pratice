#include<iostream>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		if (s.size() <= 0)
		{
			return s;
		}
		//1.删除多余空格
		//使用快慢指针
		int fast = 0;
		int slow = 0;
		//删除第一个单词之前的空格
		while (s[fast] == ' ' && fast < s.size())
		{
			++fast;
		}
		//删除单词中间多余的空格
		while (fast < s.size())
		{
			//如果连续有两个空格，则删除一个
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
		//删除末尾空格
		if (s[slow - 1] == ' ' && slow - 1 > 0)
		{
			s.resize(slow - 1);
		}
		else
		{
			s.resize(slow);
		}

		//2.逆置整个字符串
		reverse(s.begin(), s.end());
		/*for(int left = 0, right = s.size(); left <=right; ++left, --right)
		{
		swap(s[left], s[right]);
		}*/

		//3.逆置单词
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