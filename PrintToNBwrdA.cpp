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

int PrintToNBwrd(int n)		// n-1개의 순환과 나머지 1
{
	/***
	[분할]    [1,n] --> [1,n-1] n
	[일반규칙] p(n) ::= n 출력, t=p(n-1), t+n 반환
	[진행방향] n이 1씩 감소 --> 마지노선: n==1
	[중단조건] p(1) ::= 1 출력, t=p(0), t+1 반환 --> n==0, p(0) ?
	[단순해]  n==0: 출력 x, 반환 0
	***/
	if (n == 0)
		return 0;
	printf("%d ", n);
	return PrintToNBwrd(n - 1) + n;
}