#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();                       // 中
			st.pop();
			result.push_back(node->val);
			if (node->right) st.push(node->right);           // 右（空节点不入栈）
			if (node->left) st.push(node->left);             // 左（空节点不入栈）
		}
		return result;
	}
};