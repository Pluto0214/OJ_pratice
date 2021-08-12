#include<iostream>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		int count = 0;//空格数
		int OldSize = s.size();

		//计算空格数
		for (int i = 0; i < OldSize; ++i)
		{
			if (s[i] == ' ')
			{
				++count;
			}
		}

		//对s进行扩容，新空间大小 = 旧空间大小 + 2 * 空格数
		s.resize(OldSize + 2 * count);

		//用双指针从后往前对s进行遍历，替换空格
		//快指针指向旧空间的末尾，慢指针指向新空间的末尾
		for (int fast = OldSize - 1, slow = s.size() - 1; fast < slow; --fast, --slow)//当快慢指针相等时，旧说明左面没有空格了，不需要再继续遍历了
		{
			if (s[fast] == ' ')
			{
				s[slow] = '0';
				s[slow - 1] = '2';
				s[slow - 2] = '%';
				slow -= 2;
			}
			else
			{
				s[slow] = s[fast];
			}
		}
		return s;

		return s;
	}
};

int main()
{
	
	return 0;
}