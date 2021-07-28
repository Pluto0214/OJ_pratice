#include<iostream>
#include<vector>

using namespace std;

//704.二分查找
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;

	}
};

//35.搜索插入的位置
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		return left;

	}
};

//34.在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int LeftBorder = GetLeftBorder(nums, target);
		int RightBoredr = GetRightBorder(nums, target);
		//情况1 target在数组的左边或者右边，也就是说左边界或者右边界没有进行更新，返回的值还是一开始给的-2，那就返回{-1, -1}
		if (LeftBorder == -2 || RightBoredr == -2)
		{
			return{ -1, -1 };
		}
		//情况3 target在数组中且数组中有target
		if (RightBoredr - LeftBorder > 1)
		{
			return{ LeftBorder + 1, RightBoredr - 1 };
		}
		//情况2 target在数组中但数组中没有target
		return{ -1, -1 };
	}

private:
	int GetRightBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int RightBoredr = -2;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else//如果目标在右半边的话也就是要开始动left的时候，更新left的同时更新右边界
			{
				left = mid + 1;
				RightBoredr = left;
			}
		}
		return RightBoredr;
	}

	int GetLeftBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int LeftBorder = -2;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else//如果目标在左半边，更新right的同时也更新左边界
			{
				right = mid - 1;
				LeftBorder = right;
			}
		}
		return LeftBorder;
	}
};

//69.x的平方根
class Solution {
public:
	int mySqrt(int x) {
		int left = 0;
		int right = x;
		int ans = -2;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if ((long long)mid * mid > x)
			{
				right = mid - 1;
			}
			else
			{
				ans = mid;
				left = mid + 1;
			}
		}
		return ans;

	}
};

//367.有效的完全平方数
class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 0;
		int right = num;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if ((long long)mid*mid > num)
			{
				right = mid - 1;
			}
			else if ((long long)mid*mid < num)
			{
				left = mid + 1;
			}
			else
			{
				return true;
			}
		}
		return false;

	}
};

//移除元素
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;

	}
};

//26.删除有序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int slow = 0;
		int fast = 0;
		while (fast < nums.size())
		{
			if (nums[slow] != nums[fast])
			{
				++slow;
				nums[slow] = nums[fast];
			}
			++fast;
		}
		return slow + 1;

	}
};

int main()
{
	
	return 0;
}