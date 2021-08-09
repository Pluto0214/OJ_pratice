#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//��ָoffer 06 ��β��ͷ��ӡ����
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

		//����ջ
		ListNode* cur = head;
		while (cur)
		{
			st.push(cur->val);
			cur = cur->next;
		}

		//�ٳ�ջ������������
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