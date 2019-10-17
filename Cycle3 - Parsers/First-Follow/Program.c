#include<stdio.h>
#include<string.h>
	
char Productions_List[100][100][100];

void Add_Terminal_To_First(char terminal, char First[100][100],int Variable_Number)
{
	printf("\tNeed to add %c to First[%d]\n",terminal,Variable_Number);
	int len = strlen(First[Variable_Number]);
	int i,found_flag = 0;
	for(i=0;i<len;i++)
	{
		if(First[Variable_Number][i] == terminal)
		{
			printf("\tAlready Present\n");
			found_flag = 1;
			break;
		}
	}
	if(found_flag==0)
	{
		printf("\tNot Present so added at pos %d\n",len);
		First[Variable_Number][len] = terminal;
		First[Variable_Number][len+1]='\0';
	}
	return;
	
}
int AddProductionsToList( int Variable_Number, char Production[100])
{	
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


void DisplayTransitions(char Variable_List[100],int Corresponding_Number_of_Productions[100],int N)
{
	int i,j,z;
	for(i=0;i<N;i++)
	{	
		for (j=0;j<Corresponding_Number_of_Productions[i];j++)
		{	
			printf("\t%c -> ",Variable_List[i]);		
			for(z = 0 ;Productions_List[i][j][z] !='\0';z++)
			{
				printf("%c",Productions_List[i][j][z]);
			}	
			printf("\n");	
		}
	}
}


int GetVariableNumber(char Variable,char Variable_list[100],int N)
{
	int i = 0,Variable_Number;
	for(i=0;i<N;i++)
		if(Variable_list[i] == Variable)
			Variable_Number = i;
	return(Variable_Number);
}

int Find_First(char First[100][100],int Corresponding_Number_of_Productions[100],char Variable_list[100],char original,int Found[],int Total)
{	
	printf("In Func for %c\n",original);
	int i,j,N,p,len,precision,Variable_Number;
	int Next_Variable_Number;
	int Nullout = 0,position;
	char t;
	Variable_Number = GetVariableNumber(original,Variable_list,Total);
	
	if(Found[Variable_Number] == -1)
		return -1;

	if(Found[Variable_Number] == 1)
		return 1;
	
	position = 0;
	precision = 0;

	N = Corresponding_Number_of_Productions[Variable_Number];
	for(position = 0;position<=precision;position++)
	{	for(i=0;i<N;i++)
		{
			printf("In production:%s\n",Productions_List[Variable_Number][i]);
			t=Productions_List[Variable_Number][i][position];
			if(isupper(t))
			{
				printf("Is Upper\n");
				Nullout = Find_First(First,Corresponding_Number_of_Productions,Variable_list,t,Found,Total);
				Next_Variable_Number = GetVariableNumber(t,Variable_list,Total);
				len = strlen(First[Next_Variable_Number]);
				for(j=0;j<=len;j++)
				{
					Add_Terminal_To_First(First[Next_Variable_Number][j],First,Variable_Number);
				}

				if(Nullout==-1)
				{	
					len = strlen(Productions_List[Variable_Number][i]);
					if(precision<len)
					{
						printf("\t\tNeed to go 1 more round casue of #");
						precision+=1;
					}
				}
			}
			else if(t=='#')
			{ 
				Nullout=-1;
				Add_Terminal_To_First(t,First,Variable_Number);	
				Found[Variable_Number] = Nullout;
			}
			else
			{	
				Add_Terminal_To_First(t,First,Variable_Number);
				Found[Variable_Number] = 1;
			}
		}	
	}
	return(Nullout);
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
	printf("Enter The Productions:\nFormat:\tVariable -> Production1|...|Production N\n# is Epsilon ε\n");
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
	
	// Find_First()
	char First[100][100];
	int Found[100],Nullout;
	for(i=0;i<N;i++)
	{
		strcpy(First[i],"");
		Found[i]=0;
	}
	for(i=0;i<N;i++)
	{
		if(Found[i]==0)
			Nullout=Find_First(First,Corresponding_Number_of_Productions,Variable_List,Variable_List[i],Found,N);
	}
	for(i=0;i<N;i++)
	{
		printf("First(%c) -> ",Variable_List[i]);
		for(j=0;j<strlen(First[i]);j++)
			printf("%c ",First[i][j]);
		printf("\n");
	}
	
}


