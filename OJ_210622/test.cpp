#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//��β��ͷ��ӡ����
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int> st;
		vector<int> ans;

		//�Ȱ������ŵ�ջ��
		while (head)
		{
			st.push(head->val);
			head = head->next;
		}
		//Ȼ����һ��һ����ջ���ŵ�ans��
		while (!st.empty())
		{
			ans.push_back(st.top());
			st.pop();
		}

		return ans;

	}
};

//ɾ������Ľڵ�
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead->next;
		ListNode* pre = dummyHead;
		while (cur != nullptr && cur->val != val)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur != nullptr && cur->val == val)
		{
			pre->next = cur->next;
		}
		return dummyHead->next;

	}
};

//��ת����
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;

	}
};

//�����е�����k���ڵ�
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* fast = head;
		ListNode* slow = head;
		//�ÿ�ָ������k��
		while (k > 0)
		{
			fast = fast->next;
			--k;
		}

		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;

	}
};

//ɾ���м�ڵ�
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
		return;
	}
};

//�������������еĽڵ�
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;

		while (cur->next && cur->next->next)
		{
			ListNode* tmp1 = cur->next;
			ListNode* tmp2 = cur->next->next->next;

			cur->next = cur->next->next;//1
			cur->next->next = tmp1;//2
			cur->next->next->next = tmp2;//3

			cur = cur->next->next;
		}
		return dummyHead->next;

	}
};

//ɾ�����������е��ظ�Ԫ��
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* cur = head;
		while (cur && cur->next)
		{
			if (cur->val == cur->next->val)
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
		return head;

	}
};

//ɾ�������е��ظ�Ԫ��II
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;

		while (cur->next && cur->next->next)
		{
			if (cur->next->val == cur->next->next->val)
			{
				int x = cur->next->val;
				while (cur->next && cur->next->val == x)
				{
					ListNode* tmp = cur->next;
					cur->next = cur->next->next;
					delete tmp;
				}
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