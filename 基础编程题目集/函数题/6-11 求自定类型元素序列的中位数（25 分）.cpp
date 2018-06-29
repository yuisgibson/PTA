6 - 11 求自定类型元素序列的中位数（25 分）

本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第⌊N / 2 + 1⌋大的元素。其中集合元素的类型为自定义的ElementType。

函数接口定义：

ElementType Median(ElementType A[], int N);
其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。

裁判测试程序样例：

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
	ElementType A[MAXN];
	int N, i;

	scanf("%d", &N);
	for (i = 0; i<N; i++)
		scanf("%f", &A[i]);
	printf("%.2f\n", Median(A, N));

	return 0;
}

/* 你的代码将被嵌在这里 */
输入样例：

3
12.3 34 - 5
输出样例：

12.30

经过测定，O(N ^ 2) 排序会超时；快速排序也会超时。
用希尔排序AC。

ElementType Median(ElementType A[], int N) {
	for (int dk = N / 2;dk >= 1;dk /= 2) {
		for (int i = dk;i<N;++i) {
			ElementType temp;
			if (A[i]<A[i - dk]) {
				temp = A[i];
				int j;
				for (j = i - dk;j >= 0 && temp<A[j];j -= dk) {
					A[j + dk] = A[j];
				}
				A[j + dk] = temp;
			}
		}
	}
	return A[N / 2];
}