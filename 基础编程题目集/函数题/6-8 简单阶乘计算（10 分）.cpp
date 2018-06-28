6 - 8 简单阶乘计算（10 分）



本题要求实现一个计算非负整数阶乘的简单函数。

函数接口定义：
int Factorial(const int N);


其中N是用户传入的参数，其值不超过12。如果N是非负整数，则该函数必须返回N的阶乘，否则返回0。

裁判测试程序样例：
#include <stdio.h>

int Factorial(const int N);

int main()
{
	int N, NF;

	scanf("%d", &N);
	NF = Factorial(N);
	if (NF)  printf("%d! = %d\n", N, NF);
	else printf("Invalid input\n");

	return 0;
}

/* 你的代码将被嵌在这里 */


输入样例：
5


输出样例：
5!= 120

注意这里 N 为负数时返回 0 是题目定义的。

int Factorial(const int N) {
	if (N >= 0) {
		if (N == 0) {
			return 1;
		}
		else {
			int f = 1;
			for (int i = 1;i <= N;++i) {
				f *= i;
			}
			return f;
		}
	}
	else
		return 0;
}