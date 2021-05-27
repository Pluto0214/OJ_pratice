#include<iostream>
#include<vector>
using namespace std;

//���ݶ����������ַ���
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

//�������Ĳ������
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


//�������Ĳ������2
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

//�������������������
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//ȷ���ݹ����ֹ����������ҵ�p�����ҵ�q���������գ��ͷ���
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