#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//������С��������
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int ans = INT_MAX;//�����鳤�ȣ�Ĭ��Ϊ���޴�
		int start = 0, end = 0;//�������ڵĳ�ʼλ�ú�ĩλ��
		int sum = 0;//������ĺ�
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		while (end < n)//��end��������
		{
			sum += nums[end];
			while (sum >= target)
			{
				ans = min(ans, end - start + 1);//�����sum>=target��ʱ��͸��������鳤��
				sum -= nums[start];
				++start;
			}
			++end;
		}
		return ans == INT_MAX ? 0 : ans;

	}
};

//�ϲ�������������
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m - 1;
		int p2 = n - 1;
		int tail = n + m - 1;
		while (p1 >= 0 && p2 >= 0)
		{
			if (nums1[p1] <= nums2[p2])
			{
				nums1[tail] = nums2[p2];
				--p2;
			}
			else
			{
				nums1[tail] = nums1[p1];
				--p1;
			}
			--tail;
		}
		if (p1 == -1)
		{
			while (p2 >= 0)
			{
				nums1[tail] = nums2[p2];
				--p2;
				--tail;
			}
		}

	}
};

//��������II
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
		int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
		int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
		int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
		int count = 1; // ������������ÿһ���ո�ֵ
		int offset = 1; // ÿһȦѭ������Ҫ����ÿһ���߱����ĳ���
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// ���濪ʼ���ĸ�for����ģ��ת��һȦ
			// ģ��������д�����(����ҿ�)
			for (j = starty; j < starty + n - offset; j++) {
				res[startx][j] = count++;
			}
			// ģ��������д��ϵ���(����ҿ�)
			for (i = startx; i < startx + n - offset; i++) {
				res[i][j] = count++;
			}
			// ģ��������д��ҵ���(����ҿ�)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// ģ��������д��µ���(����ҿ�)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}

			// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
			startx++;
			starty++;

			// offset ����ÿһȦ��ÿһ���߱����ĳ���
			offset += 2;
		}

		// ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}
};

//���ֲ��� ����ұ�
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;

	}
};

//��������λ��
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (target < nums[mid])
			{
				right = mid - 1;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else {
				return mid;
			}
		}
		return right + 1;

	}
};


int main()
{

	return 0;
}