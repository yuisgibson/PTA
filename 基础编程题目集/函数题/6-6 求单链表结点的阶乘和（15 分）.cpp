6 - 6 ��������Ľ׳˺ͣ�15 �֣�

����Ҫ��ʵ��һ��������������L���Ľ׳˺͡�����Ĭ�����н���ֵ�Ǹ�������Ŀ��֤�����int��Χ�ڡ�

�����ӿڶ��壺

int FactorialSum(List L);
���е�����List�Ķ������£�

typedef struct Node *PtrToNode;
struct Node {
	int Data; /* �洢������� */
	PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */
���в��Գ���������

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
	int Data; /* �洢������� */
	PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

int FactorialSum(List L);

int main()
{
	int N, i;
	List L, p;

	scanf("%d", &N);
	L = NULL;
	for (i = 0; i<N; i++) {
		p = (List)malloc(sizeof(struct Node));
		scanf("%d", &p->Data);
		p->Next = L;  L = p;
	}
	printf("%d\n", FactorialSum(L));

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
����������

3
5 3 6
���������

846

�����⣬���뷽ʽ��ͷ�巨��������룩��ֱ�ӱ��������ɡ�
����׳ˣ�Ҫ���ǵ� 0 ����������� 0 �Ľ׳�Ϊ1 ����


int FactorialSum(List L) {
	int sum = 0;
	while (L != NULL) {
		if (L->Data == 0) {
			sum += 1;
		}
		else {
			int f = 1;
			for (int i = 1;i <= L->Data;++i) {
				f *= i;
			}
			sum += f;
		}
		L = L->Next;
	}
	return sum;
}