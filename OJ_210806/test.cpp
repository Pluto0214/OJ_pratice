#include<iostream>
using namespace std;

//160.相交链表
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
		//让curA永远是长的那个链表
		if (lengthB > lengthA)
		{
			swap(lengthA, lengthB);
			swap(curA, curB);
		}
		//得出长度差
		gap = lengthA - lengthB;

		//让长的链表先走，抹平长度差
		while (gap)
		{
			curA = curA->next;
			--gap;
		}

		while (curA)
		{
			//注意这里，题目说了 不是值相等，是节点相等
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

//141.环形链表
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