#include<iostream>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		int count = 0;//�ո���
		int OldSize = s.size();

		//����ո���
		for (int i = 0; i < OldSize; ++i)
		{
			if (s[i] == ' ')
			{
				++count;
			}
		}

		//��s�������ݣ��¿ռ��С = �ɿռ��С + 2 * �ո���
		s.resize(OldSize + 2 * count);

		//��˫ָ��Ӻ���ǰ��s���б������滻�ո�
		//��ָ��ָ��ɿռ��ĩβ����ָ��ָ���¿ռ��ĩβ
		for (int fast = OldSize - 1, slow = s.size() - 1; fast < slow; --fast, --slow)//������ָ�����ʱ����˵������û�пո��ˣ�����Ҫ�ټ���������
		{
			if (s[fast] == ' ')
			{
				s[slow] = '0';
				s[slow - 1] = '2';
				s[slow - 2] = '%';
				slow -= 2;
			}
			else
			{
				s[slow] = s[fast];
			}
		}
		return s;

		return s;
	}
};

int main()
{
	
	return 0;
}