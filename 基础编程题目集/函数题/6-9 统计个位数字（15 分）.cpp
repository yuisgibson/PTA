6 - 9 统计个位数字（15 分）



本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如 - 21252中，2出现了3次，则该函数应该返回3。

函数接口定义：
int Count_Digit(const int N, const int D);


其中N和D都是用户传入的参数。N的值不超过int的范围；D是[0, 9]区间内的个位数。函数须返回N中D出现的次数。

裁判测试程序样例：
#include <stdio.h>

int Count_Digit(const int N, const int D);

int main()
{
	int N, D;

	scanf("%d %d", &N, &D);
	printf("%d\n", Count_Digit(N, D));
	return 0;
}

/* 你的代码将被嵌在这里 */


输入样例：
- 21252 2


输出样例：
3

利用数组进行计数。
n == 0 时，特殊判断。
n < 0  时，先取负处理（数组下标为不为负）。

int Count_Digit(const int N, const int D) {
	int num[10] = { 0 };
	int n = N;
	if (n == 0)
		num[0]++;
	if (n<0)
		n = -n;
	while (n != 0) {
		int t = n % 10;
		num[t]++;
		n /= 10;
	}
	return num[D];
}