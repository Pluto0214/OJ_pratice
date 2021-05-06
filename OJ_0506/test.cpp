#include<iostream>
#include<vector>

//只出现一次的数字I
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			value ^= nums[i];
		}
		return value;


	}
};


//只出现一次的数字II
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//总体思路:以出现一次和出现三次作为突破口，将四个数的每一位的二进制加起来，再%3，就是只出现一次的那个数
		int res = 0;//不能让res重置，所以把res放到了循环外面
		for (int i = 0; i < 32; ++i)//nums[i]是32位数，对每一位进行二进制求和
		{
			int sum = 0;//每一次走外面这个for循环都会重置一遍sum，这样就能对二进制每一位进行求和
						//下面这个for循环对nums中的每个数的第i位进行了求和
			for (int num : nums)
			{
				sum += ((num >> i) & 1);
			}
			//对nums中的几个数的第i位求完和之后，进行if判断 如果不能被3整除，那这一位的二进制就是1而不是0
			if (sum % 3 != 0)
			{
				res |= (1 << i);
			}
		}
		return res;
	}
};

//数组中只出现一次的数字III
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//总体思路：有一个数字出现一次的时候我们采用全员异或，有两个数字出现一次的情况，我们采用全员异或然后根据异或结果进行分组，将相同的值分到一组，不同的值分成两组。
		//全员异或后的结果就是两个不同数异或的结果，我们去找第一个不为0的数（这说明了这一位他们不一样）然后根据这个位进行分组，然后再在各自的组里进行异或，这样就能反别从两个组里找到两个只出现一次的数字了。
		int res = 0; //用来存储全员异或后的值 
		int a = 0, b = 0;//两组
		int bit = 1;
		//先进行全员异或
		for (int num : nums)
		{
			res ^= num;
		}
		//找到第一个不为0的位
		while ((res & bit) == 0)
		{
			bit <<= 1;
		}
		//然后用这个不为0的位进行分组异或
		for (int num : nums)
		{
			if ((bit & num) == 0)
			{
				a ^= num;
			}
			else
			{
				b ^= num;
			}
		}
		//返回结果
		return vector<int>{a, b};
	}
};


//只出现一次的数字
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//总体思路：有一个数字出现一次的时候我们采用全员异或，有两个数字出现一次的情况，我们采用全员异或然后根据异或结果进行分组，将相同的值分到一组，不同的值分成两组。
		//全员异或后的结果就是两个不同数异或的结果，我们去找第一个不为0的数（这说明了这一位他们不一样）然后根据这个位进行分组，然后再在各自的组里进行异或，这样就能反别从两个组里找到两个只出现一次的数字了。
		int res = 0; //用来存储全员异或后的值 
		int a = 0, b = 0;//两组
		int bit = 1;
		//先进行全员异或
		for (int num : nums)
		{
			res ^= num;
		}
		//找到第一个不为0的位
		while ((res & bit) == 0)
		{
			bit <<= 1;
		}
		//然后用这个不为0的位进行分组异或
		for (int num : nums)
		{
			if ((bit & num) == 0)
			{
				a ^= num;
			}
			else
			{
				b ^= num;
			}
		}
		//返回结果
		return vector<int>{a, b};
	}
};


//删除排序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//双指针
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int fast = 0, slow = 0;
		while (fast < n)
		{
			//相同的话fast++  不同的话让slow先指向下一个位置，然后把fast赋值给slow
			if (nums[fast] == nums[slow])
			{
				++fast;
			}
			else
			{
				++slow;
				nums[slow] = nums[fast];
				++fast;
			}
		}
		return slow + 1;


	}
};

//杨辉三角
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows, vector<int>());
		for (size_t i = 0; i < vv.size(); ++i)
		{
			//先把杨辉三角的形状构建出来
			vv[i].resize(i + 1, 0);
			//然后把两边的值都 赋成1
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		//接下来遍历整个杨辉三角，把值为0的数进行填值
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;


	}
};