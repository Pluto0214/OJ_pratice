#include<iostream>
#include<vector>
using namespace std;

//根据二叉树创建字符串
class Solution {
public:


	void _tree2str(TreeNode* root, string& s)
	{
		if (root == nullptr)
		{
			return;
		}
		s += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr)
		{
			return;
		}
		s += '(';
		_tree2str(root->left, s);
		s += ')';

		if (root->right != nullptr)
		{
			s += '(';
			_tree2str(root->right, s);
			s += ')';
		}
	}

	string tree2str(TreeNode* root) {
		string s;
		_tree2str(root, s);
		return s;
	}
};

//二叉树的层序遍历
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
		{
			return vv;
		}
		vector<TreeNode*> curV;
		vector<TreeNode*> nextV;

		curV.push_back(root);
		while (!curV.empty())
		{
			vector<int> v;
			for (auto e : curV)
			{
				v.push_back(e->val);
				if (e->left)
				{
					nextV.push_back(e->left);
				}
				if (e->right)
				{
					nextV.push_back(e->right);
				}
			}
			vv.push_back(v);

			curV.swap(nextV);
			nextV.clear();
		}
		return vv;

	}
};


//二叉树的层序遍历2
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vv;

		if (root == nullptr)
		{
			return vv;
		}
		vector<TreeNode*> curV;
		vector<TreeNode*> nextV;

		curV.push_back(root);
		while (!curV.empty())
		{
			vector<int> v;
			for (auto e : curV)
			{
				v.push_back(e->val);
				if (e->left)
				{
					nextV.push_back(e->left);
				}
				if (e->right)
				{
					nextV.push_back(e->right);
				}
			}
			vv.push_back(v);

			curV.swap(nextV);
			nextV.clear();

		}
		reverse(vv.begin(), vv.end());
		return vv;

	}
};

//二叉树的最近公共祖先
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//确定递归的终止条件，如果找到p或者找到q或者遇到空，就返回
		if (root == p || root == q || root == nullptr)
		{
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != nullptr && right != nullptr)
		{
			return root;
		}
		if (left == nullptr && right != nullptr)
		{
			return right;
		}
		else if (left != nullptr && right == nullptr)
		{
			return left;
		}
		else//left == nullptr && right == nullptr
		{
			return nullptr;
		}
	}
};