#include<iostream>
#include<vector>
using namespace std;

//707.设计链表
class MyLinkedList {
public:
	//定义链表节点结构体
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int val)
			:val(val)
			, next(nullptr)
		{}
	};

	/** Initialize your data structure here. */
	//初始化链表
	MyLinkedList() {
		dummyHead = new ListNode(0);
		_size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >(_size - 1))
		{
			return -1;
		}
		ListNode* cur = dummyHead->next;
		while (index)
		{
			cur = cur->next;
			--index;
		}
		return cur->val;

	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* newNode = new ListNode(val);
		newNode->next = dummyHead->next;
		dummyHead->next = newNode;
		++_size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* newNode = new ListNode(val);
		ListNode* cur = dummyHead;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->next = nullptr;
		++_size;

	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > _size)
		{
			return;
		}
		ListNode* newNode = new ListNode(val);
		ListNode* cur = dummyHead;
		while (index)
		{
			cur = cur->next;
			--index;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		++_size;

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >(_size - 1))
		{
			return;
		}
		ListNode* cur = dummyHead;
		while (index)
		{
			cur = cur->next;
			--index;
		}
		ListNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		--_size;

	}

private:
	int _size;
	ListNode* dummyHead;
};

//反转链表
//双指针法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//双指针法
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

//递归法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//双指针法
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


//92.反转链表II
class ListNode
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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//1.加上虚拟头节点，使对头节点的操作和其他节点的操作一样
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		//2.将left~right这段切割下来
		//找到left的前一个节点
		ListNode* cur1 = dummyHead;
		int size1 = left - 1;
		while (size1)
		{
			cur1 = cur1->next;
			--size1;
		}
		//找到right这个节点
		ListNode* cur2 = dummyHead;
		int size2 = right;
		while (size2)
		{
			cur2 = cur2->next;
			--size2;
		}
		//进行切割
		ListNode* leftNode = cur1->next;
		ListNode* rightNode = cur2;
		ListNode* p = cur2->next;//right的后一个节点
		cur1->next = nullptr;
		rightNode->next = nullptr;

		//3.对这个区间进行反转
		ListNode* pre = nullptr;
		ListNode* cur = leftNode;
		while (cur != nullptr)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		//4.把反转之后的链表接上
		cur1->next = rightNode;
		leftNode->next = p;
		return dummyHead->next;

	}
};

//234.回文链表
//第一种方法
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//优化后的第一种方法(用数组)
		//先确定数组要开的长度，避免vector添加节点每次都要去开辟新空间

		int length = 0;
		ListNode* cur = head;

		//获取长度
		while (cur)
		{
			cur = cur->next;
			++length;
		}

		//给vec固定大小，避免因为添加节点vector大小不够而去开辟新空间
		vector<int> vec(length, 0);
		cur = head;
		int index = 0;

		//把链表节点值放到数组中
		while (cur)
		{
			vec[index] = cur->val;
			++index;
			cur = cur->next;
		}

		//从前从后一起遍历数组
		int i = 0;
		int j = length - 1;
		while (i <= j)
		{
			if (vec[i] != vec[j])
			{
				return false;
			}
			++i;
			--j;
		}
		return true;

	}
};

//第二种方法
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//第二种方法，使用双指针，反转链表后半部分

		//1.将链表分割成两段
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = head;//使用pre记录slow前面那个节点，方便进行分割
		while (fast && fast->next)
		{
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		pre->next = nullptr;

		//2.将后半部分链表进行反转
		ListNode* cur1 = head;
		ListNode* cur2 = reverse(slow);

		//3.比较前半段链表和后半段链表
		while (cur1)
		{
			if (cur1->val != cur2->val)
			{
				return false;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return true;


	}

	ListNode* reverse(ListNode* head)
	{
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

//19.删除链表的倒数第N个节点
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* fast = dummyHead;
		ListNode* slow = dummyHead;
		//让快指针先走n+1，这样当fast遍历完链表的时候slow刚好在倒数第n个节点的前一个
		while (n + 1)
		{
			fast = fast->next;
			--n;
		}

		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* tmp = slow->next;
		slow->next = slow->next->next;
		delete tmp;
		return dummyHead->next;

	}
};


int main()
{

	return 0;
}