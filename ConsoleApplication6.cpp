﻿// ConsoleApplication6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int  Min = 99999999; int A, B, C, D;
int main()
{
	//最后一个测试样例栈溢出了，目前只能想到这种办法（链表操作不熟练，所以没用）
	//求出最小值可以实现，但是输出此时每一个的音响分贝实现不了，栈溢出
	//用链表的话大概思路就是每次成功更新Min之后，把上一个结点释放掉
	int i, j, k, l, a[99999], b[99999], c[99999],d[99999], x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 99999, y2 = 99999, y3 = 99999, y4 = 99999;//开数组保存步骤
	 cin >> A >> B >> C >> D;
	 for ( i = 0; i <= 100; i++,x1++)
	 {
		 if (i > A) break;
		 a[x1] = i;
		 for ( j = 0; j <= 100; j++,x2++)
		 {
			 if (j > B) break;
			 b[x2] = j; 
			 for ( k = 0; k <= 100; k++,x3++)
			 {
				 if (k > C) break;
				 c[x3] = k; 
				 for (l = 0; l <= 100; l++, x4++)
				 {
					 if (i + j + k + l > Min)
					 {
						 break;
					 }
					 if (l > D) break; d[x4] = l;
					 int t1 = i + j / 3 + k / 3 + l / 2;
					 int t2 = i / 3 + j + k / 3 + l / 2;
					 int t3 = i / 3 + j / 3 + k + l / 2;
					 int t4 = i / 2 + j / 2 + k / 2 + l;
					 if (t1 >= A && t2 >= B && t3 >= C && t4 >= D)
					 {
						 //更新Min
						 if (Min > i + j + k + l)
						 {
							 Min = i + j + k + l;
							 y1 = x1; y2 = x2; y3 = x3; y4 = x4;//最小步骤对应数组操作的下标更新
						 }
					 }
				 }
				 
			 }
				 
		 }
			 
	}
	 cout << Min << endl;
	 cout << a[y1] << " " << b[y2] << " " << c[y3] << " " << d[y4] << " ";
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
