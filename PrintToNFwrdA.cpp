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
		int PrintToNFwrd(int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintToNFwrd(n));
	}
}

int PrintToNFwrd(int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할]    [1,n] --> [1,n-1] n
	[일반규칙] p(n) ::= t=p(n-1), n 출력, t+n 반환
	[진행방향] n이 1씩 감소 --> 마지노선: n==1
	[중단조건] p(1) ::= t=p(0), 1 출력, t+1 반환 --> n==0, p(0) ?
	[단순해]  n==0: 출력 x, 반환 0
	***/
	if (n == 0)
		return 0;
	int nSum = PrintToNFwrd(n - 1);
	printf("%d ", n);
	return n + nSum;
}