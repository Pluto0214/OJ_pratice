#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		//������unordered_map��map����
		unordered_map<int, int> countMap;
		//�ȼ�����ֵĴ���
		for (auto e : nums)
		{
			countMap[e]++;
		}

		//�������ҵ����ֳ��������Сһ����Ǹ�Ԫ�� 
		for (auto& e : countMap)
		{
			if (e.second == nums.size() / 2)
			{
				return e.first;
			}
		}
		return -1;

	}
};

//����������
class Solution {
public:

	int getDepth(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		//��
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1)
		{
			return -1;
		}
		//��
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1)
		{
			return -1;
		}
		//��
		return abs(rightDepth - leftDepth) > 1 ? -1 : 1 + max(rightDepth, leftDepth);
	}

	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}
};

//��������������
class Solution {
public:
	int getDepth(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);
		return 1 + max(leftDepth, rightDepth);
	}

	int maxDepth(TreeNode* root) {
		return getDepth(root);

	}
};

//����������С���
class Solution {
public:
	int getMinDepth(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int leftDepth = getMinDepth(node->left);
		int rightDepth = getMinDepth(node->right);

		if (node->left == nullptr && node->right != nullptr)
		{
			return 1 + rightDepth;
		}
		if (node->left != nullptr && node->right == nullptr)
		{
			return 1 + leftDepth;
		}
		return 1 + min(leftDepth, rightDepth);
	}

	int minDepth(TreeNode* root) {
		return getMinDepth(root);

	}
};

//��������Ľ���
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//��unordered_set ��nums1����ȥ��
		unordered_set<int> s1;
		for (auto& e : nums1)
		{
			s1.insert(e);
		}

		//ͬ���nums2����ȥ��
		unordered_set<int> s2;
		for (auto& e : nums2)
		{
			s2.insert(e);
		}

		vector<int> s3;
		for (auto& e : s1)
		{
			if (s2.find(e) != s2.end())
			{
				s3.push_back(e);
			}
		}
		return s3;

	}
};

//�ַ����еĵ�һ��Ψһ�ַ�
class Solution {
public:
	int firstUniqChar(string s) {
		int hash[26] = { 0 };
		for (auto ch : s)
		{
			hash[ch - 'a']++;
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if (hash[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};