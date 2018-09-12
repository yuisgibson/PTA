6 - 7 统计某类完全平方数（20 分）

本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。

函数接口定义：

int IsTheNumber(const int N);
其中N是用户传入的参数。如果N满足条件，则该函数必须返回1，否则返回0。

裁判测试程序样例：

#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
	int n1, n2, i, cnt;

	scanf("%d %d", &n1, &n2);
	cnt = 0;
	for (i = n1; i <= n2; i++) {
		if (IsTheNumber(i))
			cnt++;
	}
	printf("cnt = %d\n", cnt);

	return 0;
}

/* 你的代码将被嵌在这里 */
输入样例：

105 500
输出样例：

cnt = 6

1、判断完全平方数，可以用 sqrt（N）是否等于（int）sqrt（N）来判断，判断时后者会被强制转成 浮点 型
2、判断 N 是否有相同的数字，可一边遍历（ %10 再 /10 ），一边将结果计算到长 10 ，默认值为 0 的数组中（num[i]++），
   结果数组中出现大于 1 的数时为有相同数字。

int IsTheNumber(const int N) {
	int num[10] = { 0 };
	int temp = N, flag1 = 0, flag2 = 0;
	while (temp != 0) {
		int now = temp % 10;
		num[now]++;
		temp /= 10;
	}
	for (int i = 0;i<10;++i) {
		if (num[i] >= 2) {
			flag1 = 1;
		}
	}
	if (sqrt(N) == (int)sqrt(N)) {
		flag2 = 1;
	}
	if (flag1&&flag2)
		return 1;
	else
		return 0;
}