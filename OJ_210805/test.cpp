#include<iostream>
#include<vector>
using namespace std;

//707.�������
class MyLinkedList {
public:
	//��������ڵ�ṹ��
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
	//��ʼ������
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

//��ת����
//˫ָ�뷨
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//˫ָ�뷨
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

//�ݹ鷨
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//˫ָ�뷨
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


//92.��ת����II
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
		//1.��������ͷ�ڵ㣬ʹ��ͷ�ڵ�Ĳ����������ڵ�Ĳ���һ��
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;

		//2.��left~right����и�����
		//�ҵ�left��ǰһ���ڵ�
		ListNode* cur1 = dummyHead;
		int size1 = left - 1;
		while (size1)
		{
			cur1 = cur1->next;
			--size1;
		}
		//�ҵ�right����ڵ�
		ListNode* cur2 = dummyHead;
		int size2 = right;
		while (size2)
		{
			cur2 = cur2->next;
			--size2;
		}
		//�����и�
		ListNode* leftNode = cur1->next;
		ListNode* rightNode = cur2;
		ListNode* p = cur2->next;//right�ĺ�һ���ڵ�
		cur1->next = nullptr;
		rightNode->next = nullptr;

		//3.�����������з�ת
		ListNode* pre = nullptr;
		ListNode* cur = leftNode;
		while (cur != nullptr)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		//4.�ѷ�ת֮����������
		cur1->next = rightNode;
		leftNode->next = p;
		return dummyHead->next;

	}
};

//234.��������
//��һ�ַ���
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//�Ż���ĵ�һ�ַ���(������)
		//��ȷ������Ҫ���ĳ��ȣ�����vector��ӽڵ�ÿ�ζ�Ҫȥ�����¿ռ�

		int length = 0;
		ListNode* cur = head;

		//��ȡ����
		while (cur)
		{
			cur = cur->next;
			++length;
		}

		//��vec�̶���С��������Ϊ��ӽڵ�vector��С������ȥ�����¿ռ�
		vector<int> vec(length, 0);
		cur = head;
		int index = 0;

		//������ڵ�ֵ�ŵ�������
		while (cur)
		{
			vec[index] = cur->val;
			++index;
			cur = cur->next;
		}

		//��ǰ�Ӻ�һ���������
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

//�ڶ��ַ���
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//�ڶ��ַ�����ʹ��˫ָ�룬��ת�����벿��

		//1.������ָ������
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = head;//ʹ��pre��¼slowǰ���Ǹ��ڵ㣬������зָ�
		while (fast && fast->next)
		{
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		pre->next = nullptr;

		//2.����벿��������з�ת
		ListNode* cur1 = head;
		ListNode* cur2 = reverse(slow);

		//3.�Ƚ�ǰ�������ͺ�������
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

//19.ɾ������ĵ�����N���ڵ�
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* fast = dummyHead;
		ListNode* slow = dummyHead;
		//�ÿ�ָ������n+1��������fast�����������ʱ��slow�պ��ڵ�����n���ڵ��ǰһ��
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