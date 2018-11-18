#include<stdio.h>

#define W1L 5 // word 1 length
#define W2L 5 // word 1 length


char W1[] = "kerem";
char W2[] = "merek";
int SolveM[W1L+1][W2L+1];

int min(int x, int y, int z)
{
	return (x>y) ? (y > z ? z : y) : (x > z ? z : x);
}

int solve()
{
	int i,j;
	
	for(i=0;i<=W1L;i++)
		SolveM[i][0] = i;
		
	for(i=1;i<=W2L;i++)
		SolveM[0][i] = i;
		
	for(i=1;i<=W1L;i++)
		for(j=1;j<=W2L;j++)
			if(i==j && W1[i-1] == W2[j-1])
				SolveM[i][j] = SolveM[i-1][j-1];
			else
				SolveM[i][j] = min(SolveM[i-1][j-1],SolveM[i][j-1],SolveM[i-1][j]) +1;
				
	return SolveM[W1L][W2L];
}

void printM()
{
	for(int i=0;i<=W1L;i++)
	{
		puts("");
		for(int j=0;j<=W2L;j++)
		{
			printf("%d ",SolveM[i][j]);
		}
	}
}

int main()
{
	
	printM();
	printf("\nresult: %d\n", solve());
	printM();
	
	
	return 0;
}
