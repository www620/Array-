// Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
using namespace std;

bool check(int a[], int len)
{
	bool via;
	for (int i = 2; i * 2 <= len; i++)
	{
		via = true;
		for (int j = 1; j <= i; j++)
		{
			if (a[len - i - j] != a[len - j])
			{
				via = false;
				break;
			}
		}

		if (via)
			return true;
	}

	return false;
}

int Array(int n)
{
	int len = 0, maxlen = 0, maxsize = 10000;
	int* a = (int*)malloc(maxsize * 4);
	if (a == NULL)
		cout << "quit." << endl;
	a[0] = 1;

	while (a[0] <= 1)
	{
		if (len > maxlen)
			maxlen = len;
		if (len > maxsize)
		{
			maxsize += 10000;
			a = (int*)realloc(a, maxsize * 4);
			if (a == NULL)
				cout << "quit." << endl;
		}

		if (a[len - 1] > n)
		{
			len--;
			a[len - 1]++;
		}
		else if (check(a, len))
		{
			a[len - 1]++;
		}
		else
		{
			a[len] = 1;
			len++;
		}
		/*if (len > 100)
		{
			for (int i = 0; i < maxlen; i++)
				cout << a[i];
			break;
		}*/
		cout << "\b\b\b\b\b\b\b" << len;
	}
	/*for (int i = 0; i < maxlen; i++)
		cout << a[i];*/
	free(a);
	return maxlen - 1;
}

int main()
{
	//Array(3);
	cout << Array(2) << endl;
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
