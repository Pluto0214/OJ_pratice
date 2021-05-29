#include<iostream>
#include<vector>
using namespace std;

//二叉搜索树与双向链表
class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (root == nullptr)
		{
			return root;
		}
		dfs(root);
		pre->right = head;
		head->left = pre;
		return head;
	}
private:
	Node* head;
	Node* pre;
	void dfs(Node* cur)
	{
		//终止条件
		if (cur == nullptr)
		{
			return;
		}
		dfs(cur->left);//左
		if (pre == nullptr)
		{
			head = cur;
		}
		else
		{
			pre->right = cur;
			cur->left = pre;
		}
		pre = cur;
		dfs(cur->right);//右
	}

};

//void dfs(Node* root)
//{
//	if (root == nullptr)
//		return;
//	dfs(root->left);//左
//	cout << root->val << endl;//根
//	dfs(root->right);//右
//}
//int main()
//{
//	return 0;
//}

class Solution {
public:

	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0, min = arr[0];
		for (int i = 0; i < len; ++i) {
			sum += arr[i];
			min = min < arr[i] ? min : arr[i];
		}
		vector<int> v(sum + 1, 0);
		for (int i = 0; i < len; ++i) {
			for (int j = sum; j >= arr[i]; --j) {
				if (v[j] < v[j - arr[i]] + arr[i]) {
					v[j] = v[j - arr[i]] + arr[i];
				}
			}
		}
		for (int i = min; i <= sum; ++i) {
			if (i != v[i]) {
				return i;
			}
		}
		return sum + 1;
	}
};


//从中序与后序遍历序列构造二叉树
class Solution {
private:
	// 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
	TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
		if (postorderBegin == postorderEnd) return NULL;

		int rootValue = postorder[postorderEnd - 1];
		TreeNode* root = new TreeNode(rootValue);

		if (postorderEnd - postorderBegin == 1) return root;

		int delimiterIndex;
		for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue) break;
		}
		// 切割中序数组
		// 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
		int leftInorderBegin = inorderBegin;
		int leftInorderEnd = delimiterIndex;
		// 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
		int rightInorderBegin = delimiterIndex + 1;
		int rightInorderEnd = inorderEnd;

		// 切割后序数组
		// 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
		int leftPostorderBegin = postorderBegin;
		int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
																			   // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
		int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
		int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

		root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
		root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0 || postorder.size() == 0) return NULL;
		// 左闭右开的原则
		return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};

//从前序和中序遍历序列构造二叉树
class Solution {
private:
	TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
		if (preorderBegin == preorderEnd) return NULL;

		int rootValue = preorder[preorderBegin]; // 注意用preorderBegin 不要用0
		TreeNode* root = new TreeNode(rootValue);

		if (preorderEnd - preorderBegin == 1) return root;

		int delimiterIndex;
		for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue) break;
		}
		// 切割中序数组
		// 中序左区间，左闭右开[leftInorderBegin, leftInorderEnd)
		int leftInorderBegin = inorderBegin;
		int leftInorderEnd = delimiterIndex;
		// 中序右区间，左闭右开[rightInorderBegin, rightInorderEnd)
		int rightInorderBegin = delimiterIndex + 1;
		int rightInorderEnd = inorderEnd;

		// 切割前序数组
		// 前序左区间，左闭右开[leftPreorderBegin, leftPreorderEnd)
		int leftPreorderBegin = preorderBegin + 1;
		int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin; // 终止位置是起始位置加上中序左区间的大小size
																				 // 前序右区间, 左闭右开[rightPreorderBegin, rightPreorderEnd)
		int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
		int rightPreorderEnd = preorderEnd;

		root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
		root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (inorder.size() == 0 || preorder.size() == 0) return NULL;

		// 参数坚持左闭右开的原则
		return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
	}
};

//前序遍历二叉树
//递归
class Solution {
public:
	void traversal(TreeNode* cur, vector<int>& vec)
	{
		if (cur == nullptr)
		{
			return;
		}
		vec.push_back(cur->val);
		traversal(cur->left, vec);
		traversal(cur->right, vec);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;

	}
};

