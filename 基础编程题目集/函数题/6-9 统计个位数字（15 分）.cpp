6 - 9 ͳ�Ƹ�λ���֣�15 �֣�



����Ҫ��ʵ��һ����������ͳ����һ������ĳ��λ�����ֵĴ��������� - 21252�У�2������3�Σ���ú���Ӧ�÷���3��

�����ӿڶ��壺
int Count_Digit(const int N, const int D);


����N��D�����û�����Ĳ�����N��ֵ������int�ķ�Χ��D��[0, 9]�����ڵĸ�λ���������뷵��N��D���ֵĴ�����

���в��Գ���������
#include <stdio.h>

int Count_Digit(const int N, const int D);

int main()
{
	int N, D;

	scanf("%d %d", &N, &D);
	printf("%d\n", Count_Digit(N, D));
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */


����������
- 21252 2


���������
3

����������м�����
n == 0 ʱ�������жϡ�
n < 0  ʱ����ȡ�����������±�Ϊ��Ϊ������

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