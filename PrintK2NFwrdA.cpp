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

int PrintK2NFwrd1(int k, int n)		// n-1��, 1��
{
	/***
	[����]    [k,n] --> [k,n-1] n
	[�Ϲݱ�Ģ] p(k,n) ::= s=p(k,n-1), n ���, s+n ��ȯ
	[�������] n�� 1�� ���� --> �����뼱: k==n
	[�ߴ�����] p(k,k) ::= s=p(k,k-1), k ���, s+k ��ȯ --> k>n, p(k,k-1) ?
	[�ܼ���]   k>n: ��� x, ��ȯ 0
	***/
	if (k > n)
		return 0;
	int nSum = PrintK2NFwrd1(k, n - 1);
	printf("%d ", n);
	return n + nSum;
}

int PrintK2NFwrd2(int k, int n)		// 1��, n-1��
{
	/***
	[����]    [k,n] --> k [k+1,n]
	[�Ϲݱ�Ģ] p(k,n) ::= k ���, s=p(k+1,n), s+k ��ȯ
	[�������] k�� 1�� ���� --> �����뼱: k==n
	[�ߴ�����] p(n,n) ::= n ���, s=p(n+1,n), s+n ��ȯ --> k>n, p(n,n-1) ?
	[�ܼ���]   k>n: ��� x, ��ȯ 0
	***/
	if (k > n)
		return 0;
	printf("%d ", k);
	return PrintK2NFwrd2(k + 1, n) + k;
}

int PrintK2NFwrd3(int k, int n)		//  n/2��, 1��, n/2��
{
	/***
	[����]    [k,n] --> [k,m-1] m [m+1,n]
	[�Ϲݱ�Ģ] p(k,n) ::= m=(k+n)/2,
						s=p(k,m-1), m ���,
						s+=p(m+1,n),
						s+m ��ȯ
	[�������] ������ 1/2�� ���� --> �����뼱: k==n
	[�ߴ�����] p(k,k) ::= m=k,
						s=p(k,k-1), k ���,
						s+=p(k+1,k),
						s+k ��ȯ					--> k>n, p(k,k-1) ?
	[�ܼ���]   k>n: ��� x, ��ȯ 0
	***/
	if (k > n)
		return 0;
	int nMdl = (k + n) / 2;
	int nSum = PrintK2NFwrd3(k, nMdl - 1);
	printf("%d ", nMdl);
	return PrintK2NFwrd3(nMdl + 1, n) + nMdl + nSum;
}

int PrintK2NFwrd4(int k, int n)		//  n/3��, 1��, n/3��, 1��, n/3��
{
	/***
	[����]     [k,n] --> [k,m1-1] m1 [m1+1,m2-1] m2 [m2+1,n]
	[�Ϲݱ�Ģ] p(k,n) ::= nCtr=n-k+1, m1=k+nCtr/3, m2=k+nCtr*2/3
						s=p(k,m1-1), m1 ���,
						s+=p(m1+1,m2-1), m2 ���,
						s+=p(m2+1,n),
						s+m1+m2 ��ȯ
	[�������] ������ 1/3�� ���� --> �����뼱: nCtr==2, n==k+1
	[�ߴ�����]  p(k,k+1) ::= nCtr=2, m1=k, m2=k+1
						s=p(k,k-1), k ���,
						s+=p(k+1,k), k+1 ���,
						s+=p(k+2,k+1),
						s+k+k+1 ��ȯ				--> k>n, p(k,k-1) ?
	[�ܼ���]   N==1, p(k,k): ��� k, ��ȯ k
			  N==0, p(k,k-1): ��� x, ��ȯ 0
	***/
	int nCtr = n - k + 1, nSum = 0;
	if (nCtr <= 1) {				// 1�� ����
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