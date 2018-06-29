6 - 10 阶乘计算升级版（20 分）

本题要求实现一个打印非负整数阶乘的函数。

函数接口定义：

void Print_Factorial(const int N);
其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。

裁判测试程序样例：

#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
	int N;

	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}

/* 你的代码将被嵌在这里 */
输入样例：

15
输出样例：

1307674368000

重点是大整数的存储和运算。这里涉及到大整数的乘法。
当 N 为正整数时，进行大整数的运算：
定义数组 a ，a[1] = 1，其余为0.
定义 进位 carry ，当前处理数的最大位数 len 。

模拟当 N 为 5 的过程：

1、a[1] = 1，其余为 0 ，len = 1。
	temp = 1 * 1 + 0 = 1 ，carry = 0 。（1 的阶乘）

2、a[1] = 1，其余为 0 ，len = 1。
	temp = 1 * 2 + 0 = 2 ，carry = 0 。（2 的阶乘）

3、a[1] = 2，其余为 0 ，len = 1。
	temp = 2 * 3 + 0 = 6 ，carry = 0 。（3 的阶乘）

4、a[1] = 6，其余为 0 ，len = 1。
	temp = 6 * 4 + 0 = 24 ，carry = 2 ，a[j] = 4 。
	由于 j==len 且 carry = 2，len = len + 1 = 2。
	temp = 0 * 4 + 2 = 2 ，a[2] = 2。
	即 a[1] = 4 ，a[2] = 2。逆序即 24  （4 的阶乘）

5、a[1] = 4 ，a[2] = 2，其余为 0 ，len = 2。
	temp = 4 * 5 + 0 = 20 ，carry = 2 ，a[1] = 0。
	temp = 2 * 5 + 2 = 12 ，carry = 1 ，a[2] = 2。
	len++。
	temp = 0 * 5 + 1 = 1 ，a[3] = 1。
	即 a[1] = 0 ，a[2] = 2 ，a[3] = 1 。
	逆序即 120。                       （5 的阶乘）



这里其实就是一个小整数（可直接存储）和一个大整数相乘。
即 用大整数的每一位和小整数相乘，再处理进位，保证大整数每一位为个位数。
当结束后 进位不为0时，进位直接进到下一位。
输出倒序输出。


void Print_Factorial(const int N) {
	if (N >= 0) {
		if (N == 0)
			printf("1");
		else {
			int a[100000] = { 0,1 };  // 0 1 0 0 0 ...
			int len = 1;
			for (int i = 1;i <= N;++i) {
				int carry = 0;
				for (int j = 1;j <= len;++j) {
					int temp = a[j] * i + carry;
					a[j] = temp % 10;
					carry = temp / 10;
					if (j == len&&carry != 0)
						len++;
				}
			}
			for (int i = len;i >= 1;--i) {
				printf("%d", a[i]);
			}
		}
	}
	else
		printf("Invalid input");
}