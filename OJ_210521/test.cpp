
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int a[128] = { 0 };
		bool flag = false;
		for (int i = 0; i<str.size(); ++i)
			++a[str[i]];
		for (int i = 0; i<str.size(); ++i)
			if (a[str[i]] == 1)
			{
				cout << str[i] << endl;
				flag = true;
				break;
			}
		if (flag == false)
			cout << "-1" << endl;
	}
	return 0;
}


int Func(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b; b = a%b; a = temp;
	}
	return (a);
}
int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		int i, temp;
		for (i = 0; i<n; i++)
		{
			cin >> temp;
			if (c >= temp)
				c += temp;
			else
				c += Func(c, temp);
		}
		cout << c << endl;
	}
}
