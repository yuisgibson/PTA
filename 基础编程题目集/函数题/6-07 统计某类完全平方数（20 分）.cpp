6 - 7 ͳ��ĳ����ȫƽ������20 �֣�

����Ҫ��ʵ��һ���������ж���һ��������N�Ƿ�����������������ȫƽ����������������λ������ͬ����144��676�ȡ�

�����ӿڶ��壺

int IsTheNumber(const int N);
����N���û�����Ĳ��������N������������ú������뷵��1�����򷵻�0��

���в��Գ���������

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

/* ��Ĵ��뽫��Ƕ������ */
����������

105 500
���������

cnt = 6

1���ж���ȫƽ������������ sqrt��N���Ƿ���ڣ�int��sqrt��N�����жϣ��ж�ʱ���߻ᱻǿ��ת�� ���� ��
2���ж� N �Ƿ�����ͬ�����֣���һ�߱����� %10 �� /10 ����һ�߽�������㵽�� 10 ��Ĭ��ֵΪ 0 �������У�num[i]++����
   ��������г��ִ��� 1 ����ʱΪ����ͬ���֡�

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