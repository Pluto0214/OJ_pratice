#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
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
		return right + 1;

	}
};

class Solution {
public:
	int RightBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int rightborder = -2;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (nums[mid] <= target)
			{
				left = mid + 1;
				rightborder = left;
			}
			else
			{
				right = mid - 1;
			}
		}

		return rightborder;
	}

	int LeftBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int leftborder = -2;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (nums[mid] >= target)
			{
				right = mid - 1;
				leftborder = right;
			}
			else
			{
				left = mid + 1;
			}
		}

		return leftborder;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int leftborder = LeftBorder(nums, target);
		int rightborder = RightBorder(nums, target);
		if (rightborder == -2 || leftborder == -2)
		{
			return{ -1, -1 };
		}
		if (rightborder - leftborder > 1)
		{
			return{ leftborder + 1, rightborder - 1 };
		}
		return{ -1, -1 };
	}
};

int main()
{
	
	return 0;
}