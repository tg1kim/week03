#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
	while (1) {
		int k, n;
		printf("k ? ");
		scanf("%d", &k);
		if (k < 0)
			break;
		printf("n ? ");
		scanf("%d", &n);
		if (k > n)
			break;
		int PrintK2NBwrd1(int k, int n);
		int PrintK2NBwrd2(int k, int n);
		int PrintK2NBwrd3(int k, int n);
		int PrintK2NBwrd4(int k, int n);
		int PrintK2NBwrd5(int k, int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd1(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd2(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd3(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd4(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NBwrd5(k, n));
	}
}

// k���� n���� �Ųٷ� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintK2NBwrd1(int k, int n)		// n-1��, 1��
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(k,n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	return 0;
}

int PrintK2NBwrd2(int k, int n)		// 1��, n-1��
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(k,n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	return 0;
}

int PrintK2NBwrd3(int k, int n)		// n/2��, 1��, n/2��
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(k,n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	return 0;
}

int PrintK2NBwrd4(int k, int n)		// n/3��, 1��, n/3��, 1��, n/3��
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(k,n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	return 0;
}

int PrintK2NBwrd5(int k, int n)		// n/4��, 1��, n/4��, 1��, n/4��, 1��, n/4��
{
	/***
	[����] ?
	[�Ϲݱ�Ģ] p(k,n) ::= ?
	[�������] ?
	[�ߴ�����] ?
	[�ܼ���] ?
	***/
	return 0;
}
