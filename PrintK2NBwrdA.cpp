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

int PrintK2NBwrd1(int k, int n)		// n-1개, 1개
{
	/***
	[분할]    [k,n] --> [k,n-1] n
	[일반규칙] p(k,n) ::= n 출력, s=p(k,n-1), s+n 반환
	[진행방향] n이 1씩 감소 --> 마지노선: k==n
	[중단조건] p(k,k) ::= k 출력, s=p(k,k-1), s+k 반환 --> k>n, p(k,k-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	printf("%d ", n);
	return PrintK2NBwrd1(k, n - 1) + n;
}

int PrintK2NBwrd2(int k, int n)		// 1개, n-1개
{
	/***
	[분할]    [k,n] --> k [k+1,n] 
	[일반규칙] p(k,n) ::= s=p(k+1,n), k 출력, s+k 반환
	[진행방향] k가 1씩 증가 --> 마지노선: k==n
	[중단조건] p(n,n) ::= s=p(n+1,n), n 출력, s+n 반환 --> k>n, p(n,n-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	int nSum = PrintK2NBwrd2(k + 1, n);
	printf("%d ", k);
	return k + nSum;
}

int PrintK2NBwrd3(int k, int n)		// n/2개, 1개, n/2개
{
	/***
	[분할]    [k,n] --> [k,m-1] m [m+1,n] 
	[일반규칙] p(k,n) ::= m=(k+n)/2, 
						s=p(m+1,n), m 출력, 
						s+=p(k,m-1), 
						s+m 반환
	[진행방향] 범위가 1/2로 감소 --> 마지노선: k==n
	[중단조건] p(k,k) ::= m=k, 
						s=p(k+1,k), k 출력, 
						s+=p(k,k-1), 
						s+k 반환					--> k>n, p(k,k-1) ?
	[단순해]   k>n: 출력 x, 반환 0
	***/
	if (k > n)
		return 0;
	int nMdl = (k + n) / 2;
	int nSum = PrintK2NBwrd3(nMdl + 1, n);
	printf("%d ", nMdl);
	return PrintK2NBwrd3(k, nMdl - 1) + nMdl + nSum;
}

int PrintK2NBwrd4(int k, int n)		// n/3개, 1개, n/3개, 1개, n/3개
{
	/***
	[분할]     [k,n] --> [k,m1-1] m1 [m1+1,m2-1] m2 [m2+1,n] 
	[일반규칙] p(k,n) ::= nCtr=n-k+1, m1=k+nCtr/3, m2=k+nCtr*2/3
						s=p(m2+1,n), m2 출력, 
						s+=p(m1+1,m2-1), m1 출력,
						s+=p(k,m1-1), 
						s+m1+m2 반환
	[진행방향] 범위가 1/3로 감소 --> 마지노선: nCtr==2, n==k+1
	[중단조건]  p(k,k+1) ::= nCtr=2, m1=k, m2=k+1
						s=p(k+2,k+1), k+1 출력, 
						s+=p(k+1,k), k 출력,
						s+=p(k,k-1), 
						s+k+k+1 반환				--> k>n, p(k,k-1) ?
	[단순해]   N==1, p(k,k): 출력 k, 반환 k
			  N==0, p(k,k-1): 출력 x, 반환 0
	***/
	int nCtr = n - k + 1, nSum = 0;
	if (nCtr <= 1) {				// 1개 이하
		if (nCtr == 1) {
			printf("%d ", k);
			nSum = k;
		}
		return nSum;
	}
	// 최소 2개는 필요
	int nMdl1 = k + nCtr / 3, nMdl2 = k + nCtr * 2 / 3;
	nSum = PrintK2NBwrd4(nMdl2 + 1, n);
	printf("%d ", nMdl2);
	nSum += PrintK2NBwrd4(nMdl1 + 1, nMdl2 - 1);
	printf("%d ", nMdl1);
	nSum += PrintK2NBwrd4(k, nMdl1 - 1);
	return nSum + nMdl1 + nMdl2;
}

int PrintK2NBwrd5(int k, int n)		// n/4개, 1개, n/4개, 1개, n/4개, 1개, n/4개
{
	/***
	[분할]    [k,n] --> [k,m1-1] m1 [m1+1,m2-1] m2 [m2+1,m3-1] m3 [m3+1,n]
	[일반규칙] p(k,n) ::= nCtr=n-k+1, m1=k+nCtr/4, m2=k+nCtr/2, m3=k+nCtr*3/4
						s=p(m3+1,n), m3 출력,
						s+=p(m2+1,m3-1), m2 출력,
						s+=p(m1+1,m2-1), m1 출력,
						s+=p(k,m1-1),
						s+m1+m2+m3 반환
	[진행방향] 범위가 1/4로 감소 --> 마지노선: nCtr==3, n==k+2
	[중단조건] p(k,k+2) ::= nCtr=3, m1=k, m2=k+1, m3=k+2
						s=p(k+3,k+2), k+2 출력,
						s+=p(k+2,k+1), k+1 출력,
						s+=p(k+1,k), k 출력,
						s+=p(k,k-1),
						s+k+k+1+k+2 반환			--> k>n, p(k,k-1) ?
	[단순해]   N==2, p(k,k+1): 출력 k+1 k, 반환 k+k+1
			  N==1, p(k,k): 출력 k, 반환 k
			  N==0, p(k,k-1): 출력 x, 반환 0
	***/
	int nCtr = n - k + 1, nSum = 0;
	if (nCtr <= 2) {				// 2개 이하
		switch (nCtr) {
		case 2:
			printf("%d ", k + 1);
			nSum += k + 1;
		case 1:
			printf("%d ", k);
			nSum += k;
		}
		return nSum;
	}
	// 최소 3개는 필요
	int nMdl1 = k + nCtr / 4, nMdl2 = k + nCtr / 2, nMdl3 = k + nCtr * 3 / 4;
	nSum = PrintK2NBwrd5(nMdl3 + 1, n);
	printf("%d ", nMdl3);
	nSum += PrintK2NBwrd5(nMdl2 + 1, nMdl3 - 1);
	printf("%d ", nMdl2);
	nSum += PrintK2NBwrd5(nMdl1 + 1, nMdl2 - 1);
	printf("%d ", nMdl1);
	nSum += PrintK2NBwrd5(k, nMdl1 - 1);
	return nSum + nMdl1 + nMdl2 + nMdl3;
}