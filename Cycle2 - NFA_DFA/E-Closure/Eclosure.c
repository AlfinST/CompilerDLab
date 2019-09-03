#include <stdio.h>
#include<string.h>
struct State
{
	char name[10];
	char Transitions[10][50]
}S[10];

int CheckForIn(char A[],char c)
{

}

void main()
{	 
	char EpsilonClosure[10][50];
	char Trans[50];
	int Stack[10];
	int Visited[10];	
	int N,i,j,k,l,top=0,Vcount=0,VFlag;
	printf("Enter The Number of States:");
	scanf("%d",&N);
	printf("Enter Names of States:\n");
	//Get the name
	for(i=0;i<N;i++)
	{
		scanf("%s",&S[i].name);	
	}
	//Enter Transitions
	for(i=0;i<N;i++)
	{
		printf("Enter Transitions for state %s\n",S[i].name);
		for (j=0;j<N;j++)
		{	//Entering Name : Transitions 
			printf("to %s : ",S[j].name);
			scanf("%s",S[i].Transitions[j]);
		}	
	}


/*	Testing
	for(i=0;i<N;i++)
	{
		printf("%s\n",S[i].name);
		for(j=0;j<N;j++)
		{
			printf("%s\t",S[j].name);
		}
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("%s\t",S[i].Transitions[j]);
		}
		printf("\n");
	}

*/
	// Strip the string Also
	for(i=0;i<N;i++)
	{	//Selecting the State
		top=0;
		for(j=0;j<N;j++)
		{	// Selecting form list of Strings
			strcpy(S[i].Transitions[j],Trans);
			
			for (k=0;Trans[k]!='\0';k++)
			{	// Going Element by Element 
				// Yes , I am Aware of this mistake below
				if(Trans[k]=='e' && (Trans[k+1]=='\0' || Trans[k+1]==','))
					//Check if Visited
					VFlag = 0;
					if(Vcount ==0)
						{
							Stack[top++]=j;
							Visited[Vcount]=j;
							Vcount++;
						}
					else
					{
						for(l=0;l<Vcount;l++)
						{
							if (j == Visited[l])
								VFlag=1;
						}
						if (VFlag == 0)
						{
							Visited[Vcount] = j;
								Vcount++;
							Stack[top++] = j;
						}
					}
			}
			// We get the States we can reach by E -Tran in Stack
			printf("%s has Epsilon States:\n",S[i].name);
			for(l=0;l<top;l++)
			{
				printf("\t%s\n",S[Stack[l]].name);
			}
		}
	}
}
