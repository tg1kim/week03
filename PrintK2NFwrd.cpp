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
		int PrintK2NFwrd1(int k, int n);
		int PrintK2NFwrd2(int k, int n);
		int PrintK2NFwrd3(int k, int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd1(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd2(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd3(k, n));
	}
}

// k���� n���� ����ϰ� �׵��� ���� ��ȯ�Ѵ�
int PrintK2NFwrd1(int k, int n)		// n-1���� ��ȯ�� ������ 1
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

int PrintK2NFwrd2(int k, int n)		// 1���� ������ n-1���� ��ȯ
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

int PrintK2NFwrd3(int k, int n)		//  n/2��, 1��, n/2���� ��ȯ
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