#include<iostream>
#include<vector>

using namespace std;

//283.�ƶ���
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] != 0)
			{
				swap(nums[slow], nums[fast]);
				++slow;
			}
			++fast;
		}

	}
};

//844.�ȽϺ��˸�����ַ���
//˫ָ�뷽��
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		//˫ָ�� �Ӻ���ǰ�����ַ�����ȥ���˸�����˸��Ҫɾ������ĸ����ÿ����ĸ���бȽ�
		int i = s.size() - 1;
		int j = t.size() - 1;
		int SNum = 0;//��¼s�е�#��Ŀ
		int TNum = 0;//t��#����Ŀ

		while (1)
		{
			//��s����ѭ������
			while (i >= 0)
			{
				//����ַ���#�Ļ�������#����Ŀ+1
				if (s[i] == '#')
				{
					++SNum;
				}
				//����ַ�����ĸ�Ļ�����������ۣ������ʱ#����Ŀ����0���Ǿ�Ҫ������i����--(�൱��ɾ�����˸��Ҫ�˵����Ǹ��ַ�)�����û��#�ˣ��ǾͿ����������s��ѭ��������t�еĶ�Ӧ�ַ����бȽ���
				else
				{
					if (SNum > 0)
					{
						--SNum;
					}
					else
					{
						break;
					}
				}
				--i;
			}

			//t�ַ���s�ַ�ͬ��
			while (j >= 0)
			{
				if (t[j] == '#')
				{
					++TNum;
				}
				else
				{
					if (TNum > 0)
					{
						--TNum;
					}
					else
					{
						break;
					}
				}
				--j;
			}

			//s��t����������ѭ����i��j���бȽϣ������ȵĻ��Ǿͼ����ص����Ե�ѭ�������У��������Ⱦ�ֱ�ӵó�����ˣ������һ���ַ����Ѿ��������˵Ļ����Ǿ����������ѭ��
			if (j < 0 || i < 0)
			{
				break;
			}
			if (s[i] != t[j])
			{
				return false;
			}
			//�ߵ��������û�б����겢��������ĸ��ȣ���ʱ���Ҫ����s��t���Ե�ѭ���������ˣ�������ﲻ��ij����--�Ļ��ͻᷢ����ѭ��
			--i;
			--j;

		}
		//����ߵ��������s��tͬʱ���������ˣ��Ǿ�˵���������ַ�����һ���ģ�
		if (j == -1 && i == -1)
		{
			return true;
		}
		return false;

	}
};


int main()
{

	return 0;
}
