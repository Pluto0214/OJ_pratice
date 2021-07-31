#include<iostream>
#include<vector>
using namespace std;

//977.���������ƽ��
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

//������С��������
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int begin = 0;//�������ڵĳ�ʼλ��
		int end = 0;//�������ڵ�ĩβֵ
		int sum = 0;//�������ڵ���ֵ֮��
		int length = 0;//�������ڵĳ���
		int result = INT32_MAX;

		while (end < nums.size())//���������ѭ������end��nums���б���
		{
			sum += nums[end];
			while (sum >= target)//��������ѭ����ֻҪ��ֵ��>target���Ǿ���begin�������������ܲ�����С�������ڲ���������ֵ��>target������
			{
				length = end - begin + 1;
				result = length < result ? length : result;//����С���Ƚ��и���
				sum -= nums[begin];//������ǻ������ڸı��С�ľ����ˣ�end��������begin��
				++begin;
			}
			++end;
		}
		return result == INT32_MAX ? 0 : result;

	}
};

//203.�Ƴ�����Ԫ��

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
		//��������ͷ�ڵ㣬����ɾ��ͷ�ڵ��ʱ��ͺ�ɾ�������ڵ�Ĳ���һ����
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