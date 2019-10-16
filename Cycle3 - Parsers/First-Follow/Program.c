#include<stdio.h>
#include<string.h>
	
char Productions_List[100][100][100];

void DisplayTransitions(char Variable_List[100],int Corresponding_Number_of_Productions[100],int N)
{
	int i,j,z;
	for(i=0;i<N;i++)
	{	
		for (j=0;j<Corresponding_Number_of_Productions[i];j++)
		{	
			printf(" %c -> ",Variable_List[i]);		
			for(z = 0 ;Productions_List[i][j][z] !='\0';z++)
			{
				printf("%c",Productions_List[i][j][z]);
			}	
			printf("\n");	
		}
	}
}

int AddProductionsToList( int Variable_Number, char Production[100])
{	
	// printf("Adding to Variable_Number:%d -> %s\n",Variable_Number,Production);
	int i,j,len;
	int Production_Number = 0;
	len = strlen(Production);
	for(i=0,j=0;i<len;i++)
	{
		if (Production[i] == '|')
			{	
				Productions_List[Variable_Number][Production_Number][j] = '\0';
				Production_Number ++;
				j=0;
			}
		else
			{
				Productions_List[Variable_Number][Production_Number][j] = Production[i];
				j++;  	
			}
	}

	return(Production_Number+1);
}
	

void main(void)
{
	int N,i,j,z;
	int Number_of_Productions = 0,Variable_Number = 0;
	char Variable, Start_Variable ='S' , Production[100];
	char Variable_List[100];
	int Corresponding_Number_of_Productions[100];
	printf("Enter number of Productions:");
	scanf("%d",&N);
	printf("Enter The Productions:\nFormat:\tVariable -> Production\n# is Epsilon ε\n");
	printf("S -> ");
	scanf("%s",Production);
	
	Variable_List[Variable_Number] = Start_Variable;
	Number_of_Productions = AddProductionsToList(Variable_Number, Production);
	Corresponding_Number_of_Productions[Variable_Number]= Number_of_Productions;
	Variable_Number++;

	for(i=1;i<N;i++)
	{
		scanf("\n%c -> %s",&Variable,Production);
		Variable_List[Variable_Number] = Variable;
		Number_of_Productions = AddProductionsToList(Variable_Number, Production);
		Corresponding_Number_of_Productions[Variable_Number] = Number_of_Productions;	
		Variable_Number++;
	}

	DisplayTransitions(Variable_List,Corresponding_Number_of_Productions,N);
	

	
}
