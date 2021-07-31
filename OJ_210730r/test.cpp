#include<iostream>
#include<vector>
using namespace std;

//977.有序数组的平方
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res(nums.size());
		int left = 0;
		int right = nums.size() - 1;
		int p = nums.size() - 1;
		while (left <= right)
		{
			if (nums[left] * nums[left] >= nums[right] * nums[right])
			{
				res[p] = nums[left] * nums[left];
				++left;
			}
			else
			{
				res[p] = nums[right] * nums[right];
				--right;
			}
			--p;
		}
		return res;

	}
};

//长度最小的子数组
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int begin = 0;//滑动窗口的初始位置
		int end = 0;//滑动窗口的末尾值
		int sum = 0;//滑动窗口的数值之和
		int length = 0;//滑动窗口的长度
		int result = INT32_MAX;

		while (end < nums.size())//外面这个大循环是让end对nums进行遍历
		{
			sum += nums[end];
			while (sum >= target)//里面的这个循环是只要数值和>target了那就让begin向左移来看看能不能缩小滑动窗口并且满足数值和>target的条件
			{
				length = end - begin + 1;
				result = length < result ? length : result;//对最小长度进行更新
				sum -= nums[begin];//这里就是滑动窗口改变大小的精髓了，end不动，让begin动
				++begin;
			}
			++end;
		}
		return result == INT32_MAX ? 0 : result;

	}
};

//203.移除链表元素

struct ListNode {
	ListNode* next;
	int val;
	ListNode(int x)
		:val(x)
		,next(next)
	{}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//设置虚拟头节点，这样删除头节点的时候就和删除其他节点的操作一样了
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		while (cur->next)
		{
			if (cur->next->val == val)
			{
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else
			{
				cur = cur->next;
			}
		}
		return dummyHead->next;

	}
};


int main()
{

	return 0;
}