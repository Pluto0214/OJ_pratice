#include<vector>
#include<iostream>
#include<stack>
using namespace std;

//二叉树的前序遍历 递归
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

//二叉树的前序遍历 迭代
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

//中序
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
		//递归
		vector<int> result;
		traversal(result, root);
		return result;

	}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//迭代
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())
		{
			//用指针访问结点，访问到最底层
			if (cur != nullptr)
			{
				st.push(cur);//把遍历的这些结点依次放入到栈中
				cur = cur->left;//左
			}
			else//已经到最下面了，开始处理节点
			{
				cur = st.top();
				result.push_back(cur->val);//中
				st.pop();
				cur = cur->right;//右
			}
		}
		return result;

	}
};


//后序
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

//移除元素
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

//删除有序数组中的重复元素
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

//删除有序数组中的重复项II
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

//移动零
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

//有序数组的平方
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
