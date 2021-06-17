#include<iostream>
using namespace std;

//x��ƽ����
class Solution {
public:
	int mySqrt(int x) {
		int left = 0;
		int right = x;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if ((long long)mid*mid > x)
			{
				right = mid - 1;
			}
			else if ((long long)mid*mid < x)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return right;

	}
};

//�Ƴ�����Ԫ��
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//ֱ��ʹ��ԭ����������в���
		//ɾ��ͷ���
		while (head != nullptr && head->val == val)
		{
			ListNode* tmp = head;//���ﱣ��һ�£�����һ������ͷŵ�
			head = head->next;
			delete tmp;
		}

		ListNode* cur = head;
		//ɾ����ͷ�ڵ�
		while (cur != nullptr && cur->next != nullptr)
		{
			if (cur->next->val == val)
			{
				ListNode* node = cur->next;
				cur->next = cur->next->next;
				delete node;
			}
			else
			{
				cur = cur->next;
			}
		}
		return head;

	}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//ʹ������ͷ�ڵ�
		ListNode* dummynode = new ListNode(0);//����һ������ͷ�ڵ�
											  //Ȼ������ͷ�ڵ��nextָ��ͷ�ڵ㣬��������ָ��head��next�ˣ��������Ҫ�Ļ������head����ɾ��
		dummynode->next = head;
		ListNode* cur = dummynode;
		while (cur != nullptr && cur->next != nullptr)
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
		dummynode->next = head;
		return head;

	}
};

//�������
class MyLinkedList {
public:
	/** Initialize your data structure here. */

	//��������ڵ�ṹ
	struct LinkedNode
	{
		int val;
		LinkedNode* next;
		LinkedNode(int val)
			:val(val)
			, next(nullptr)
		{}
	};

	//�����ʼ��
	MyLinkedList() {
		_dummyHead = new LinkedNode(0);
		_size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		LinkedNode* cur = _dummyHead->next;
		if (index < 0 || index >(_size - 1))
		{
			return -1;
		}
		while (index)
		{
			cur = cur->next;
			--index;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		LinkedNode* newnode = new LinkedNode(val);
		newnode->next = _dummyHead->next;
		_dummyHead->next = newnode;
		++_size;

	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		LinkedNode* newnode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		//���ҵ����һ���ڵ�
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		++_size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > _size)
		{
			return;
		}
		LinkedNode* newnode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (index)
		{
			cur = cur->next;
			--index;
		}
		newnode->next = cur->next;
		cur->next = newnode;
		++_size;

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index > _size - 1)
		{
			return;
		}
		LinkedNode* cur = _dummyHead;
		while (index)
		{
			cur = cur->next;
			--index;
		}
		LinkedNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		--_size;

	}

private:
	LinkedNode* _dummyHead;
	int _size;
};


int main()
{

	return 0;
}