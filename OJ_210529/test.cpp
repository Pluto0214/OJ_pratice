#include<iostream>
#include<vector>
using namespace std;

//������������˫������
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
		//��ֹ����
		if (cur == nullptr)
		{
			return;
		}
		dfs(cur->left);//��
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
		dfs(cur->right);//��
	}

};

//void dfs(Node* root)
//{
//	if (root == nullptr)
//		return;
//	dfs(root->left);//��
//	cout << root->val << endl;//��
//	dfs(root->right);//��
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


//�����������������й��������
class Solution {
private:
	// �������䣺[inorderBegin, inorderEnd)����������[postorderBegin, postorderEnd)
	TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
		if (postorderBegin == postorderEnd) return NULL;

		int rootValue = postorder[postorderEnd - 1];
		TreeNode* root = new TreeNode(rootValue);

		if (postorderEnd - postorderBegin == 1) return root;

		int delimiterIndex;
		for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue) break;
		}
		// �и���������
		// ���������䣬����ҿ�[leftInorderBegin, leftInorderEnd)
		int leftInorderBegin = inorderBegin;
		int leftInorderEnd = delimiterIndex;
		// ���������䣬����ҿ�[rightInorderBegin, rightInorderEnd)
		int rightInorderBegin = delimiterIndex + 1;
		int rightInorderEnd = inorderEnd;

		// �и��������
		// ��������䣬����ҿ�[leftPostorderBegin, leftPostorderEnd)
		int leftPostorderBegin = postorderBegin;
		int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // ��ֹλ���� ��Ҫ���� ��������Ĵ�Сsize
																			   // �Һ������䣬����ҿ�[rightPostorderBegin, rightPostorderEnd)
		int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
		int rightPostorderEnd = postorderEnd - 1; // �ų����һ��Ԫ�أ��Ѿ���Ϊ�ڵ���

		root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
		root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0 || postorder.size() == 0) return NULL;
		// ����ҿ���ԭ��
		return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};

//��ǰ�������������й��������
class Solution {
private:
	TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
		if (preorderBegin == preorderEnd) return NULL;

		int rootValue = preorder[preorderBegin]; // ע����preorderBegin ��Ҫ��0
		TreeNode* root = new TreeNode(rootValue);

		if (preorderEnd - preorderBegin == 1) return root;

		int delimiterIndex;
		for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue) break;
		}
		// �и���������
		// ���������䣬����ҿ�[leftInorderBegin, leftInorderEnd)
		int leftInorderBegin = inorderBegin;
		int leftInorderEnd = delimiterIndex;
		// ���������䣬����ҿ�[rightInorderBegin, rightInorderEnd)
		int rightInorderBegin = delimiterIndex + 1;
		int rightInorderEnd = inorderEnd;

		// �и�ǰ������
		// ǰ�������䣬����ҿ�[leftPreorderBegin, leftPreorderEnd)
		int leftPreorderBegin = preorderBegin + 1;
		int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin; // ��ֹλ������ʼλ�ü�������������Ĵ�Сsize
																				 // ǰ��������, ����ҿ�[rightPreorderBegin, rightPreorderEnd)
		int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
		int rightPreorderEnd = preorderEnd;

		root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
		root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (inorder.size() == 0 || preorder.size() == 0) return NULL;

		// �����������ҿ���ԭ��
		return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
	}
};

//ǰ�����������
//�ݹ�
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

