#include<iostream>
#include<vector>
using namespace std; 

//344.反转字符串
class Solution {
public:
	void reverseString(vector<char>& s) {
		//双指针
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

//541.反转字符串II
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//每次让i走2k个，就能实现 每2k个字符...了
		{
			//剩余字符大于k和大于2k的情况是一样的
			if (s.size() - i >= k)
			{
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else//将剩余字符全部反转
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