#include<iostream>
using namespace std;

//160.�ཻ����
struct ListNode
{
	int _val;
	ListNode* next;
	ListNode(int val)
		:_val(val)
		,next(nullptr)
	{}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int gap = 0;
		int lengthA = 0;
		int lengthB = 0;

		ListNode* curA = headA;
		while (curA)
		{
			++lengthA;
			curA = curA->next;
		}
		ListNode* curB = headB;
		while (curB)
		{
			++lengthB;
			curB = curB->next;
		}
		curA = headA;
		curB = headB;
		//��curA��Զ�ǳ����Ǹ�����
		if (lengthB > lengthA)
		{
			swap(lengthA, lengthB);
			swap(curA, curB);
		}
		//�ó����Ȳ�
		gap = lengthA - lengthB;

		//�ó����������ߣ�Ĩƽ���Ȳ�
		while (gap)
		{
			curA = curA->next;
			--gap;
		}

		while (curA)
		{
			//ע�������Ŀ˵�� ����ֵ��ȣ��ǽڵ����
			if (curA == curB)
			{
				return curA;
			}
			curA = curA->next;
			curB = curB->next;
		}
		return NULL;
	}
};

//141.��������
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{

	return 0;
}