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
		int PrintK2NFwrd4(int k, int n);
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd1(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd2(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd3(k, n));
		printf(" Print: ");
		printf("\nReturn: %d\n\n", PrintK2NFwrd4(k, n));
	}
}

int PrintK2NFwrd1(int k, int n)		// n-1개, 1개
{
	/***
	[분할]    [k,n] --> [k,n-1] n
	[일반규칙] p(k,n) ::= s=p(k,n-1), n 출력, s+n 반환
	[진행방향] n이 1씩 감소 --> 마지노선: k==n
	[중단조건] p(k,k) ::= s=p(k,k-1), k 출력, s+k 반환 --> k>n, p(k,k-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	int nSum = PrintK2NFwrd1(k, n - 1);
	printf("%d ", n);
	return n + nSum;
}

int PrintK2NFwrd2(int k, int n)		// 1개, n-1개
{
	/***
	[분할]    [k,n] --> k [k+1,n]
	[일반규칙] p(k,n) ::= k 출력, s=p(k+1,n), s+k 반환
	[진행방향] k가 1씩 증가 --> 마지노선: k==n
	[중단조건] p(n,n) ::= n 출력, s=p(n+1,n), s+n 반환 --> k>n, p(n,n-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	printf("%d ", k);
	return PrintK2NFwrd2(k + 1, n) + k;
}

int PrintK2NFwrd3(int k, int n)		//  n/2개, 1개, n/2개
{
	/***
	[분할]    [k,n] --> [k,m-1] m [m+1,n]
	[일반규칙] p(k,n) ::= m=(k+n)/2,
						s=p(k,m-1), m 출력,
						s+=p(m+1,n),
						s+m 반환
	[진행방향] 범위가 1/2로 감소 --> 마지노선: k==n
	[중단조건] p(k,k) ::= m=k,
						s=p(k,k-1), k 출력,
						s+=p(k+1,k),
						s+k 반환					--> k>n, p(k,k-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	int nMdl = (k + n) / 2;
	int nSum = PrintK2NFwrd3(k, nMdl - 1);
	printf("%d ", nMdl);
	return PrintK2NFwrd3(nMdl + 1, n) + nMdl + nSum;
}

int PrintK2NFwrd4(int k, int n)		//  n/3개, 1개, n/3개, 1개, n/3개
{
	/***
	[분할]     [k,n] --> [k,m1-1] m1 [m1+1,m2-1] m2 [m2+1,n]
	[일반규칙] p(k,n) ::= nCtr=n-k+1, m1=k+nCtr/3, m2=k+nCtr*2/3
						s=p(k,m1-1), m1 출력,
						s+=p(m1+1,m2-1), m2 출력,
						s+=p(m2+1,n),
						s+m1+m2 반환
	[진행방향] 범위가 1/3로 감소 --> 마지노선: nCtr==2, n==k+1
	[중단조건]  p(k,k+1) ::= nCtr=2, m1=k, m2=k+1
						s=p(k,k-1), k 출력,
						s+=p(k+1,k), k+1 출력,
						s+=p(k+2,k+1),
						s+k+k+1 반환				--> k>n, p(k,k-1) ?
	[단순해]   N==1, p(k,k): 출력 k, 반환 k
			  N==0, p(k,k-1): 출력 x, 반환 0
	***/
	int nCtr = n - k + 1, nSum = 0;
	if (nCtr <= 1) {				// 1개 이하
		if (k == n) {
			printf("%d ", k);
			nSum = k;
		}
		return nSum;
	}
	int nMdl1 = k + nCtr / 3, nMdl2 = k + nCtr * 2 / 3;
	nSum = PrintK2NFwrd4(k, nMdl1 - 1);
	printf("%d ", nMdl1);
	nSum += PrintK2NFwrd4(nMdl1 + 1, nMdl2 - 1);
	printf("%d ", nMdl2);
	nSum += PrintK2NFwrd4(nMdl2 + 1, n);
	return nSum + nMdl1 + nMdl2;
}