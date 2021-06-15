#include<vector>
#include<iostream>
#include<stack>
using namespace std;

//��������ǰ����� �ݹ�
class Solution {
public:
	void traversal(vector<int>& vec, TreeNode* cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		vec.push_back(cur->val);
		traversal(vec, cur->left);
		traversal(vec, cur->right);

	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(result, root);
		return result;

	}
};

//��������ǰ����� ����
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
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
			if (node->right)
			{
				st.push(node->right);
			}
			if (node->left)
			{
				st.push(node->left);
			}
		}
		return result;

	}
};

//����
class Solution {
public:
	void traversal(vector<int>& vec, TreeNode* cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		traversal(vec, cur->left);
		vec.push_back(cur->val);
		traversal(vec, cur->right);

	}

	vector<int> inorderTraversal(TreeNode* root) {
		//�ݹ�
		vector<int> result;
		traversal(result, root);
		return result;

	}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//����
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())
		{
			//��ָ����ʽ�㣬���ʵ���ײ�
			if (cur != nullptr)
			{
				st.push(cur);//�ѱ�������Щ������η��뵽ջ��
				cur = cur->left;//��
			}
			else//�Ѿ����������ˣ���ʼ����ڵ�
			{
				cur = st.top();
				result.push_back(cur->val);//��
				st.pop();
				cur = cur->right;//��
			}
		}
		return result;

	}
};


//����
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		stack<TreeNode*> st;
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

//�Ƴ�Ԫ��
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++fast;
				++slow;
			}
			else
			{
				++fast;
			}
		}
		return slow;

	}
};

//ɾ�����������е��ظ�Ԫ��
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != nums[slow])
			{
				++slow;
				nums[slow] = nums[fast];
			}
			++fast;
		}
		return slow + 1;

	}
};

//ɾ�����������е��ظ���II
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) 
		{
			return n;
		}
		int slow = 2, fast = 2;
		while (fast < n) 
		{
			if (nums[slow - 2] != nums[fast]) 
			{
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;
	}
};

//�ƶ���
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int fast = 0, slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast])
			{
				swap(nums[slow], nums[fast]);
				++slow;
			}
			++fast;
		}

	}
};

//���������ƽ��
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		int k = n - 1;
		vector<int> vec(n, 0);

		while (left <= right)
		{
			if (nums[left] * nums[left] < nums[right] * nums[right])
			{
				vec[k] = nums[right] * nums[right];
				--right;
			}
			else
			{
				vec[k] = nums[left] * nums[left];
				++left;
			}
			--k;
		}
		return vec;

	}
};
