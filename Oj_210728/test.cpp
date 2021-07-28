#include<iostream>
#include<vector>

using namespace std;

//704.���ֲ���
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

//35.���������λ��
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

//34.�����������в���Ԫ�صĵ�һ�������һ��λ��
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int LeftBorder = GetLeftBorder(nums, target);
		int RightBoredr = GetRightBorder(nums, target);
		//���1 target���������߻����ұߣ�Ҳ����˵��߽�����ұ߽�û�н��и��£����ص�ֵ����һ��ʼ����-2���Ǿͷ���{-1, -1}
		if (LeftBorder == -2 || RightBoredr == -2)
		{
			return{ -1, -1 };
		}
		//���3 target������������������target
		if (RightBoredr - LeftBorder > 1)
		{
			return{ LeftBorder + 1, RightBoredr - 1 };
		}
		//���2 target�������е�������û��target
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
			else//���Ŀ�����Ұ�ߵĻ�Ҳ����Ҫ��ʼ��left��ʱ�򣬸���left��ͬʱ�����ұ߽�
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
			else//���Ŀ�������ߣ�����right��ͬʱҲ������߽�
			{
				right = mid - 1;
				LeftBorder = right;
			}
		}
		return LeftBorder;
	}
};

//69.x��ƽ����
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

//367.��Ч����ȫƽ����
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

//�Ƴ�Ԫ��
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

//26.ɾ�����������е��ظ���
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