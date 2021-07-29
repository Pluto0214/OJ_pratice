#include<iostream>
#include<vector>

using namespace std;

//283.移动零
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != 0)
			{
				swap(nums[slow], nums[fast]);
				++slow;
			}
			++fast;
		}

	}
};

//844.比较含退格符的字符串
//双指针方法
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		//双指针 从后往前遍历字符串，去掉退格符和退格符要删掉的字母，对每个字母进行比较
		int i = s.size() - 1;
		int j = t.size() - 1;
		int SNum = 0;//记录s中的#数目
		int TNum = 0;//t中#的数目

		while (1)
		{
			//对s进行循环遍历
			while (i >= 0)
			{
				//如果字符是#的话，就让#的数目+1
				if (s[i] == '#')
				{
					++SNum;
				}
				//如果字符是字母的话，分情况讨论，如果这时#的数目大于0，那就要继续对i进行--(相当于删除了退格符要退掉的那个字符)，如果没有#了，那就可以跳出这个s的循环遍历于t中的对应字符进行比较了
				else
				{
					if (SNum > 0)
					{
						--SNum;
					}
					else
					{
						break;
					}
				}
				--i;
			}

			//t字符于s字符同理
			while (j >= 0)
			{
				if (t[j] == '#')
				{
					++TNum;
				}
				else
				{
					if (TNum > 0)
					{
						--TNum;
					}
					else
					{
						break;
					}
				}
				--j;
			}

			//s和t各自跳出了循环对i和j进行比较，如果相等的话那就继续回到各自的循环遍历中，如果不相等就直接得出结果了，如果有一个字符串已经遍历完了的话，那就跳出这个大循环
			if (j < 0 || i < 0)
			{
				break;
			}
			if (s[i] != t[j])
			{
				return false;
			}
			//走到这里就是没有遍历完并且两个字母相等，这时候就要返回s和t各自的循环遍历中了，如果这里不对ij进行--的话就会发生死循环
			--i;
			--j;

		}
		//如果走到这里，并且s和t同时被遍历完了，那就说明这两个字符串是一样的，
		if (j == -1 && i == -1)
		{
			return true;
		}
		return false;

	}
};


int main()
{

	return 0;
}
