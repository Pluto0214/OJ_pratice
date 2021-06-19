#include<iostream>
using namespace std;

//�ཻ����
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
		//��������������Եĳ���
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

		//�����곤��֮�󣬼ǵ�Ҫ��curA��curB����ָ������ͷ�ڵ�
		curA = headA;
		curB = headB;

		//��curAָ��ϳ��������䳤��ΪlenA
		if (lenB > lenA)
		{
			swap(lenA, lenB);
			swap(curA, curB);
		}
		//������������ĳ��Ȳ�
		int gap = lenA - lenB;

		//��curA��������gap
		while (gap)
		{
			curA = curA->next;
			--gap;
		}
		//����ͬ�Ľ��
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

//��������
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

//��������II
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		//���ж��Ƿ��л�
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				//���ҵ��������
				//ָ��ͷ�ڵ��ָ��Ϳ���ָ�������ĵط�һ�������ߣ������ĵط����ǻ������
				ListNode* p1 = head;//p1ָ��ͷ�ڵ�
				ListNode* p2 = fast;//p2ָ�����ָ�������ĵط�
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

//�滻�ո�
class Solution {
public:
	string replaceSpace(string s) {
		//��ͳ���ж��ٸ��ո�
		int count = 0;
		int oldsize = s.size();
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				++count;
			}
		}
		//���������ݵ�ÿ���ո��滻��%20�Ĵ�С
		s.resize(s.size() + count * 2);

		int a, b;
		int newsize = s.size();
		//��aָ���¿ռ��С��ĩβ  bָ��ɿռ��С��ĩβ
		//Ȼ��Ӻ���ǰ��ʼ���� ��b��ֵ����a ���bָ����ǿո��Ǿ͸�a����%20
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

