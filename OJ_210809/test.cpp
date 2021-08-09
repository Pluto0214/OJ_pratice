#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//剑指offer 06 从尾到头打印链表
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int val)
		:val(val)
		,next(nullptr)
	{}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> vec;
		stack<int> st;

		//先入栈
		ListNode* cur = head;
		while (cur)
		{
			st.push(cur->val);
			cur = cur->next;
		}

		//再出栈，放入数组中
		while (!st.empty())
		{
			vec.push_back(st.top());
			st.pop();
		}
		return vec;

	}
};

int main()
{

	return 0;
}