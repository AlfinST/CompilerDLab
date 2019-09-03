/*

	BE SMART AND JUST DO THIS WITH LINKED LISTS.....
	I WAS BORED AND WANTED OT TRY SOMETHING OUT.

*/

#include <stdio.h>
#include<string.h>
struct State
{
	char name[10];
	char Transitions[10][50];
	int Epsilons[10];
	int EpsTop;
}S[10];

void main()
{	 
	int EpsilonClosure[10];
	char Trans[50]="";
	int Stack[10];
	int Visited[10];	
	int N,i,j,k,l,d=0,done,E=0,top=0,Vcount=0,VFlag,OldE;
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
	// Strip the string Also
	for(i=0;i<N;i++)
	{	//Selecting the State
		top=0;
		for(j=0;j<N;j++)
		{	// Selecting from list of Strings
			strcpy(Trans,S[i].Transitions[j]);
			// printf("checking %s:\n",Trans);
			for (k=0;Trans[k]!='\0';k++)
			{
				// Going Element by Element 
				// Yes , I am Aware of this mistake below
				if(Trans[k]==','|| Trans[k]==' ')
					continue;
				if(Trans[k]=='e' && (Trans[k+1]=='\0' || Trans[k+1]==','))
				{	//Check if Visited
					VFlag = 0;
					if(Vcount ==0)
						{
							Stack[top++]=j;
							Visited[Vcount]=j;
							Vcount++;
							// printf("\nfreebie\n");
						}
				
					else
					{
						for(l=0;l<Vcount;l++)
						{
							if (j == Visited[l])
								VFlag=1;
						}
						if (VFlag == 0)
						{	//printf("Added %d to Stack\n",j);
							Visited[Vcount] = j;
								Vcount++;
							Stack[top++] = j;
						}
						// else
						// {
						// 	printf("Already found in Stack\n");
						// }
						
					}
				}
			}
		
		}

		printf("%s has Epsilons to:\n",S[i].name);
		for(l=0;l<top;l++)
		{
			printf("\t%s\n",S[Stack[l]].name);
			S[i].Epsilons[l]=Stack[l];
		}
		S[i].EpsTop=top;
		top=0;
		Vcount=0;
	}

//	Testing
	for(i=0;i<N;i++)
	{
		printf("\n\\%s\n",S[i].name);
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("%s\t",S[i].Transitions[j]);
		}
		printf("Epsilon Count :: %d\n",S[i].EpsTop);
	}
	//Getting CLosure
	for(i=0;i<N;i++)
	{
		EpsilonClosure[0]=i;
		E=1;
		done =0;
		d=i;
		Vcount=0;
		// printf("Startig with %s\n",S[i].name);
		while (!done)
		{	OldE =E;
			if(Vcount>=E)
			{
				done = 1;
			}
			// printf("\tWhile:Looking into %s\n",S[d].name);
			for(j=0;j<S[d].EpsTop;j++)
			{
				VFlag=0;
				for (k=0;k<E;k++)
				{
					// printf("\t\t\tchecking S[%d].Epsilons[%d]  (%d) == EpsilonClosure[%d]  (%d) \n",d,j,S[d].Epsilons[j],k,EpsilonClosure[k]);
					if(S[d].Epsilons[j] == EpsilonClosure[k])
						{	
							// printf("\t\t\tAlready Present\n");
							VFlag = 1;
						}
				}
				if(VFlag == 0)
				{	
					// printf("\t\t Added %d to Closure\n",S[d].Epsilons[j]);
					EpsilonClosure[E++]=S[d].Epsilons[j];
					//Vcount++;
					//printf("\t\t\tVcount incremented to %d\n",Vcount);	
				}
			}
			//else
			//{
				if(OldE==E )
				{
					Vcount++;
					// printf("\t\t\tSame E so Vcount++ %d\n",Vcount);
				}
			//}
			if(Vcount>=E)
			{
				done = 1;
			}
			d=EpsilonClosure[++Vcount];
			// printf("\t\tUpdated d to %d\n",d);
			if(d>Vcount)
				d=-1;
		}
		printf("\n\t\tClosure of %s ::\n",S[i].name);
		for(j=0;j<E;j++)

			printf("\t\t%s\n",S[EpsilonClosure[j]].name);

	}


}