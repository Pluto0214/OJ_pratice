#include<iostream>
using namespace std;

//相交链表
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}
		ListNode* curA = headA;
		ListNode* curB = headB;
		int lenA = 0, lenB = 0;
		//计算两个链表各自的长度
		while (curA)
		{
			curA = curA->next;
			++lenA;
		}
		while (curB)
		{
			curB = curB->next;
			++lenB;
		}

		//计算完长度之后，记得要把curA被curB重新指向链表头节点
		curA = headA;
		curB = headB;

		//让curA指向较长的链表，其长度为lenA
		if (lenB > lenA)
		{
			swap(lenA, lenB);
			swap(curA, curB);
		}
		//计算两个链表的长度差
		int gap = lenA - lenB;

		//让curA先往后移gap
		while (gap)
		{
			curA = curA->next;
			--gap;
		}
		//找相同的结点
		while (curA)
		{
			if (curA == curB)
			{
				return curA;
			}
			curA = curA->next;
			curB = curB->next;
		}
		return nullptr;
	}
};

//环形链表
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}
};

//环形链表II
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		//先判断是否有环
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				//再找到环的入口
				//指向头节点的指针和快慢指针相遇的地方一起往后走，相遇的地方就是环的入口
				ListNode* p1 = head;//p1指向头节点
				ListNode* p2 = fast;//p2指向快慢指针相遇的地方
				while (p1 != p2)
				{
					p1 = p1->next;
					p2 = p2->next;
				}
				return p1;
			}
		}
		return nullptr;

	}
};

//替换空格
class Solution {
public:
	string replaceSpace(string s) {
		//先统计有多少个空格
		int count = 0;
		int oldsize = s.size();
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				++count;
			}
		}
		//把数组扩容到每个空格都替换成%20的大小
		s.resize(s.size() + count * 2);

		int a, b;
		int newsize = s.size();
		//让a指向新空间大小的末尾  b指向旧空间大小的末尾
		//然后从后往前开始遍历 把b的值赋给a 如果b指向的是空格，那就给a附上%20
		for (a = newsize - 1, b = oldsize - 1; b < a; --b, --a)
		{
			if (s[b] == ' ')
			{
				s[a] = '0';
				s[a - 1] = '2';
				s[a - 2] = '%';
				a -= 2;
			}
			else
			{
				s[a] = s[b];
			}
		}
		return s;

	}
};

