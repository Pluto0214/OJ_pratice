#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//最小栈
class MinStack {
public:
	/** initialize your data structure here. */

	//要支持LIFO后进先出，采用双栈思路（一般这种检索栈中最小元素会用双栈）
	//一个普通栈（用来存数据） 一个最小栈 （用来存最小元素）
	MinStack() {

	}

	void push(int val) {
		_st.push(val);
		if (_minSt.empty() || _minSt.top() >= val)
		{
			_minSt.push(val);
		}

	}

	void pop() {

		if (_st.top() == _minSt.top())
		{
			_minSt.pop();
		}
		_st.pop();
	}

	int top() {
		return _st.top();

	}

	int getMin() {
		return _minSt.top();

	}
private:
	stack<int> _st;
	stack<int> _minSt;


};


//栈的压入、弹出序列
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> st;
		size_t pushi = 0, popi = 0;
		while (pushi < pushV.size())
		{
			st.push(pushV[pushi]);
			while (!st.empty() && (st.top() == popV[popi]))
			{
				st.pop();
				popi++;
			}
			pushi++;
		}
		if (popi == popV.size())
			return true;
		else
			return false;
	}
};

//计算日期到天数转换
#include<iostream>
using namespace std;
int dataToDay(int year, int month, int day)
{
	if (year <= 0 || month <= 0 || month>12 || day>31 || day <= 0) return -1;
	int lemp[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int Nolemp[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool flag;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		flag = true;
	}
		
	else
	{
		flag = false;
	}
		
	if (flag)
	{
		if (day>lemp[month - 1]) return -1;
	}
	else
	{
		if (day>Nolemp[month - 1]) return -1;
	}
	int temp = 0;
	for (int i = 0; i<month - 1; i++)
	{
		if (flag)
		{
			temp = temp + lemp[i];
		}
		else
		{
			temp = temp + Nolemp[i];
		}
			
	}
	return temp + day;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << dataToDay(year, month, day) << endl;
	}
}