#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
	while (1) {
		printf("n ? ");
		int n;
		scanf("%d", &n);
		if (n < 0)
			break;
		int PrintToNBwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNBwrd(n));
	}
}

int PrintToNBwrd(int n)		// n-1���� ��ȯ�� ������ 1
{
	/***
	[����]    [1,n] --> [1,n-1] n
	[�Ϲݱ�Ģ] p(n) ::= n ���, t=p(n-1), t+n ��ȯ
	[�������] n�� 1�� ���� --> �����뼱: n==1
	[�ߴ�����] p(1) ::= 1 ���, t=p(0), t+1 ��ȯ --> n==0, p(0) ?
	[�ܼ���]  n==0: ��� x, ��ȯ 0
	***/
	if (n == 0)
		return 0;
	printf("%d ", n);
	return PrintToNBwrd(n - 1) + n;
}