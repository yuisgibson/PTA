6-2 ����ʽ��ֵ��15 �֣�

����Ҫ��ʵ��һ���������������Ϊn��ϵ��Ϊa[0] ... a[n]�Ķ���ʽ
        i = 0
f(x)=��      (a[i]��x^i)
?        n
��x���ֵ��

�����ӿڶ��壺

double f( int n, double a[], double x );
����n�Ƕ���ʽ�Ľ�����a[]�д洢ϵ����x�Ǹ����㡣�����뷵�ض���ʽf(x)��ֵ��

���в��Գ���������

#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf(��%lf��, &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
����������

2 1.1
1 2.5 -38.7
���������

-43.1

ֱ��ѭ���ۼӣ�fx Ϊ x ��i�η���

double f(int n, double a[], double x) {
	double fin = a[0], fx = 1;
	for (int i = 1;i <= n;++i) {
		fx *= x;
		fin += a[i] * fx;
	}
	return fin;
}