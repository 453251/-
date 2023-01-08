// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//利用深度优先搜索

#include <iostream>
using namespace std;
char a[3] = { '+','-','^' };//用char数组来存储对应操作
char s[100];
int n, j, top, Min=99999999;
int dfs(int step,int num)
{
    int i;
    if (step>Min)
    {
        return 0;
    }
    if (num == 1)
    {
        Min = step;
        cout << step << endl;
        for (i = 0; i < step; i++)
            cout << s[i];
        cout << endl;
        return 0;
    }
    for (i = 2; i>=0; i--)//要让num尽可能的趋向于1，那么首先考虑除法，在考虑减法，最后考虑加法，这样尽可能保证是最小的步骤
    {
        if (a[i] == '+')
        {
            s[j] = a[i];
            j++;
            dfs(step + 1,num+1);
            j--;
        }
        if(a[i]=='-') 
        {
            s[j] = a[i];
            j++;
            dfs(step + 1,num-1);
            j--;
        }
        if(a[i]=='^'&& num%2==0)
        {
            
            s[j] = a[i];
            j++;
            dfs(step + 1,num/2);
            j--;
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    dfs(0,n);
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
