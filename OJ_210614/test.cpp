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
			TreeNode* node = st.top();                       // ��
			st.pop();
			result.push_back(node->val);
			if (node->right) st.push(node->right);           // �ң��սڵ㲻��ջ��
			if (node->left) st.push(node->left);             // �󣨿սڵ㲻��ջ��
		}
		return result;
	}
};