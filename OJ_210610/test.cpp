#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		//这里用unordered_map和map都行
		unordered_map<int, int> countMap;
		//先计算出现的次数
		for (auto e : nums)
		{
			countMap[e]++;
		}

		//接下来找到出现出现数组大小一半的那个元素 
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

//二叉搜索树
class Solution {
public:

	int getDepth(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		//左
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1)
		{
			return -1;
		}
		//右
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1)
		{
			return -1;
		}
		//中
		return abs(rightDepth - leftDepth) > 1 ? -1 : 1 + max(rightDepth, leftDepth);
	}

	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}
};

//二叉树的最大深度
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

//二叉树的最小深度
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

//两个数组的交集
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//用unordered_set 对nums1进行去重
		unordered_set<int> s1;
		for (auto& e : nums1)
		{
			s1.insert(e);
		}

		//同理对nums2进行去重
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

//字符串中的第一个唯一字符
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