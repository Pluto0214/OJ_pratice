#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//长度最小的子数组
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int ans = INT_MAX;//子数组长度，默认为无限大
		int start = 0, end = 0;//滑动窗口的初始位置和末位置
		int sum = 0;//子数组的和
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		while (end < n)//用end遍历数组
		{
			sum += nums[end];
			while (sum >= target)
			{
				ans = min(ans, end - start + 1);//如果当sum>=target的时候就更新子数组长度
				sum -= nums[start];
				++start;
			}
			++end;
		}
		return ans == INT_MAX ? 0 : ans;

	}
};

//合并两个有序数组
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m - 1;
		int p2 = n - 1;
		int tail = n + m - 1;
		while (p1 >= 0 && p2 >= 0)
		{
			if (nums1[p1] <= nums2[p2])
			{
				nums1[tail] = nums2[p2];
				--p2;
			}
			else
			{
				nums1[tail] = nums1[p1];
				--p1;
			}
			--tail;
		}
		if (p1 == -1)
		{
			while (p2 >= 0)
			{
				nums1[tail] = nums2[p2];
				--p2;
				--tail;
			}
		}

	}
};

//螺旋矩阵II
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
		int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
		int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
		int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
		int count = 1; // 用来给矩阵中每一个空格赋值
		int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// 下面开始的四个for就是模拟转了一圈
			// 模拟填充上行从左到右(左闭右开)
			for (j = starty; j < starty + n - offset; j++) {
				res[startx][j] = count++;
			}
			// 模拟填充右列从上到下(左闭右开)
			for (i = startx; i < startx + n - offset; i++) {
				res[i][j] = count++;
			}
			// 模拟填充下行从右到左(左闭右开)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// 模拟填充左列从下到上(左闭右开)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}

			// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
			startx++;
			starty++;

			// offset 控制每一圈里每一条边遍历的长度
			offset += 2;
		}

		// 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}
};

//二分查找 左闭右闭
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;

	}
};

//搜索插入位置
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (target < nums[mid])
			{
				right = mid - 1;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else {
				return mid;
			}
		}
		return right + 1;

	}
};


int main()
{

	return 0;
}