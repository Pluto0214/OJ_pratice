#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//二叉树的中序遍历
class Solution {
public:
	void traversal(TreeNode* cur, vector<int>& vec)
	{
		if (cur == nullptr)
		{
			return;
		}
		traversal(cur->left, vec);
		vec.push_back(cur->val);
		traversal(cur->right, vec);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;

	}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//非递归
		stack<TreeNode*> st;
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())
		{
			if (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;

	}
};


//二叉树的后序遍历
class Solution {
public:
	void traversal(TreeNode* cur, vector<int>& vec)
	{
		if (cur == nullptr)
		{
			return;
		}
		traversal(cur->left, vec);
		traversal(cur->right, vec);
		vec.push_back(cur->val);

	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;

	}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		//非递归 
		stack<TreeNode*> st;
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left)
			{
				st.push(node->left);
			}
			if (node->right)
			{
				st.push(node->right);
			}

		}
		reverse(result.begin(), result.end());
		return result;

	}
};

int main()
{
	return 0;
}