#include<iostream>
#include<vector>

//ֻ����һ�ε�����I
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			value ^= nums[i];
		}
		return value;


	}
};


//ֻ����һ�ε�����II
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//����˼·:�Գ���һ�κͳ���������Ϊͻ�ƿڣ����ĸ�����ÿһλ�Ķ����Ƽ���������%3������ֻ����һ�ε��Ǹ���
		int res = 0;//������res���ã����԰�res�ŵ���ѭ������
		for (int i = 0; i < 32; ++i)//nums[i]��32λ������ÿһλ���ж��������
		{
			int sum = 0;//ÿһ�����������forѭ����������һ��sum���������ܶԶ�����ÿһλ�������
						//�������forѭ����nums�е�ÿ�����ĵ�iλ���������
			for (int num : nums)
			{
				sum += ((num >> i) & 1);
			}
			//��nums�еļ������ĵ�iλ�����֮�󣬽���if�ж� ������ܱ�3����������һλ�Ķ����ƾ���1������0
			if (sum % 3 != 0)
			{
				res |= (1 << i);
			}
		}
		return res;
	}
};

//������ֻ����һ�ε�����III
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//����˼·����һ�����ֳ���һ�ε�ʱ�����ǲ���ȫԱ������������ֳ���һ�ε���������ǲ���ȫԱ���Ȼ�������������з��飬����ͬ��ֵ�ֵ�һ�飬��ͬ��ֵ�ֳ����顣
		//ȫԱ����Ľ������������ͬ�����Ľ��������ȥ�ҵ�һ����Ϊ0��������˵������һλ���ǲ�һ����Ȼ��������λ���з��飬Ȼ�����ڸ��Ե������������������ܷ�������������ҵ�����ֻ����һ�ε������ˡ�
		int res = 0; //�����洢ȫԱ�����ֵ 
		int a = 0, b = 0;//����
		int bit = 1;
		//�Ƚ���ȫԱ���
		for (int num : nums)
		{
			res ^= num;
		}
		//�ҵ���һ����Ϊ0��λ
		while ((res & bit) == 0)
		{
			bit <<= 1;
		}
		//Ȼ���������Ϊ0��λ���з������
		for (int num : nums)
		{
			if ((bit & num) == 0)
			{
				a ^= num;
			}
			else
			{
				b ^= num;
			}
		}
		//���ؽ��
		return vector<int>{a, b};
	}
};


//ֻ����һ�ε�����
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		//����˼·����һ�����ֳ���һ�ε�ʱ�����ǲ���ȫԱ������������ֳ���һ�ε���������ǲ���ȫԱ���Ȼ�������������з��飬����ͬ��ֵ�ֵ�һ�飬��ͬ��ֵ�ֳ����顣
		//ȫԱ����Ľ������������ͬ�����Ľ��������ȥ�ҵ�һ����Ϊ0��������˵������һλ���ǲ�һ����Ȼ��������λ���з��飬Ȼ�����ڸ��Ե������������������ܷ�������������ҵ�����ֻ����һ�ε������ˡ�
		int res = 0; //�����洢ȫԱ�����ֵ 
		int a = 0, b = 0;//����
		int bit = 1;
		//�Ƚ���ȫԱ���
		for (int num : nums)
		{
			res ^= num;
		}
		//�ҵ���һ����Ϊ0��λ
		while ((res & bit) == 0)
		{
			bit <<= 1;
		}
		//Ȼ���������Ϊ0��λ���з������
		for (int num : nums)
		{
			if ((bit & num) == 0)
			{
				a ^= num;
			}
			else
			{
				b ^= num;
			}
		}
		//���ؽ��
		return vector<int>{a, b};
	}
};


//ɾ�����������е��ظ���
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//˫ָ��
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int fast = 0, slow = 0;
		while (fast < n)
		{
			//��ͬ�Ļ�fast++  ��ͬ�Ļ���slow��ָ����һ��λ�ã�Ȼ���fast��ֵ��slow
			if (nums[fast] == nums[slow])
			{
				++fast;
			}
			else
			{
				++slow;
				nums[slow] = nums[fast];
				++fast;
			}
		}
		return slow + 1;


	}
};

//�������
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows, vector<int>());
		for (size_t i = 0; i < vv.size(); ++i)
		{
			//�Ȱ�������ǵ���״��������
			vv[i].resize(i + 1, 0);
			//Ȼ������ߵ�ֵ�� ����1
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		//��������������������ǣ���ֵΪ0����������ֵ
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;


	}
};