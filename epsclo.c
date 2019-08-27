#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
void epsclo(int state, char m[][3], char trav[][3], int lim)
{	
	for(int i=0;i<lim;i++)
	{	
		if(m[state][i]=='e' && trav[state][i]==0)
		{
			trav[state][i]=1;
			printf("\t%d\t", i);
			epsclo(i, m, trav, lim);
		}
	}
	return;
}
int main()
{
	int t;
	int i,j;
	char a;
	printf("Enter number of states: ");
	scanf("%d",&n);
	char m[n][n];
	int trav[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			m[i][j] = 'x';
			trav[i][j] = 0;
		}	
	printf("Enter number of transistions: ");
	scanf(" %d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d %c %d",&i,&a,&j);
		m[i][j] = a;
	}
	for(int k=0;k<n;k++)
	{
		printf("\nEpsilon closure of %d : %d", k, k);
		epsclo(k, m, trav, n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)	
				trav[i][j] = 0;

	}
	printf("\n");
	return 0;
}
