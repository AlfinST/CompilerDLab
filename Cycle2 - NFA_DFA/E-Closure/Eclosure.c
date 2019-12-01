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
	int N,m,i,j,k,l,d=0,done,E=0,top=0,Vcount=0,VFlag,OldE;
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
	/*
	This Area below is for the sole purpose of understanding the input.
	It searches the Transitions and finds the "e" transition.
		All the searching is done directly below.
	Once found it adds that index to the Epsilons array of the object
	and it also sets the EspsTop to top of stack.
	*/
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
/*
	Prints the entire table 
*/

//	Testing
	for(i=0;i<N;i++)
	{
		printf("\t%s",S[i].name);
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("\n%s\t",S[i].name);
		for(j=0;j<N;j++)
		{
			printf("%s\t",S[i].Transitions[j]);
		}
		printf("Epsilon Count :: %d\n",S[i].EpsTop);
	}
	//Getting CLosure
	for(i=0;i<N;i++)
	{
		/* 
			Fill the Closure with -1
			And pick the starting State
				have a counter to indicate index in the EpsilonClosure Array
				Compare elements of States epsilons with the EpsilonClosure array:
					if not in Closure Array:
						Add it ot Closure Array
					else
						ignore/continue
				change the State to next from counter;
			print the Closure
		*/
		for(m=0;m<10;m++)
			EpsilonClosure[m]=-1;
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
						//	printf("\t\t\tAlready Present\n");
							VFlag = 1;
						}
				}
				if(VFlag == 0)
				{	
				//	printf("\t\t Added %d to Closure\n",S[d].Epsilons[j]);
					EpsilonClosure[E++]=S[d].Epsilons[j];
				}
			}
			if(Vcount>=E)
			{
				done = 1;
			}
			d=EpsilonClosure[++Vcount];
			//printf("\t\tUpdated d to %d\n",d);
			if(d==-1)
				{
					d=-1;
					done =1;
				}
		}
		printf("\n\tClosure of %s ::\n",S[i].name);
		for(j=0;j<E;j++)

			printf("\t\t\t%s\n",S[EpsilonClosure[j]].name);

	}


}