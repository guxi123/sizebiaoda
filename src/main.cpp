#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void boom()
{
	float x, y;
	int z, t;		//x,y分别表示所产生的两个数，z来控制做加减乘除
	int first_num, second_num, third_num, fourth_num;
	srand(time(NULL));
	int n;
	float k;
	float d;//代表输入的答案
	float daan[100];//代表正确答案
	int zq = 0;//用来表示正确答案的个数
	int cw = 0;//用来表示错误答案的个数
	cout << "需要列出多少道数学题?" << endl;
	cin >> n;
	cout << "********************************" << endl;
	for (int i = 0; i<n; i++)
	{
		z = rand() % 4;
		first_num = rand() % 10;
		second_num = rand() % 10;
		third_num = rand() % 10;
		fourth_num = rand() % 10;
		if (second_num == 1)
		{
			x = (float)first_num;
		}
		else if (first_num>second_num)
		{
			t = first_num;
			first_num = second_num;
			second_num = t;
		}
		x = (float)first_num / second_num;
		if (fourth_num == 1)
		{
			y = (float)third_num;
		}
		else if (third_num>fourth_num)
		{
			t = third_num;
			third_num = fourth_num;
			fourth_num = t;
		}
		y = (float)third_num / fourth_num;
		z = rand() % 4;
		switch (z)
		{
		case 0:
			cout << i + 1 << "、 " << first_num << "/" << second_num << "+" << third_num << "/" << fourth_num << "=" << "     ";
			daan[i + 1] = x + y;
			break;

		case 1:
			cout << i + 1 << "、 " << first_num << "/" << second_num << "-" << third_num << "/" << fourth_num << "=" << "     ";
			daan[i + 1] = x - y;
			break;
		case 2:
			cout << i + 1 << "、 " << first_num << "/" << second_num << "*" << third_num << "/" << fourth_num << "=" << "     ";
			daan[i + 1] = x*y;
			break;
		case 3:
			if (y != 0)
			{
				cout << i + 1 << "、 " << first_num << "/" << second_num << "÷" << third_num << "/" << fourth_num << "=" << "     ";
			}
			else
			{
				i = i - 1;
			}
			daan[i + 1] = (float)x / y;
			break;
		}
		if ((i + 1) % 3 == 0)
		{
			for (int c = 0; c <= 1; c++)
			{
				cout << endl;
			}
		}
		if ((i + 1) == n)
		{
			cout << endl;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "请作答:" << endl;
		cout << i << "、";
		cin >> d;
		if (d == daan[i])
		{
			cout << "恭喜您，回答正确！" << endl;
			cout << endl;
			zq = zq + 1;
		}
		else
		{
			cout << "回答错误，正确答案为：" << "  " << daan[i] << endl;
			cout << endl;
			cw = cw + 1;
		}
	}
	k = (float)zq / n;
	cout << "回答正确的数量为：" << " " << zq << "个" << endl;
	cout << "回答错误的数量为：" << " " << cw << "个" << endl;
	cout << "正确率为：" << " " << k << endl;
}
int main()
{
	boom();
	int c;//c代表输入是否继续的数字
	cout << "要继续答题吗？（0：继续  1：退出）" << endl;
	cin >> c;
	if (c == 0)
	{
		cout << endl;
		main();
	}
	else
	{
		cout << endl;
		return 0;
	}

	return 0;
}