//#include<stdio.h>

struct Structure
{
	int Struct_var_1;
	float Struct_var_2;
	char Arr[10]
}

void Message(int a, char c)
{
	char Msg = "Merry X-Mas" + c; 
	if (a!=1337)
	{
		return;
	}
	else
	{
		printf("And Happy New Year !!");
	}
}

void main()
{
	int Integer_Var;
	char Character_Var;
	for(int i=0; i<10;)
	{
		printf("Hello World\n");
		i++;
	}
	printf("Enter a Number: ");
	scanf("%d",&Integer_Var);

	Message(Integer_Var)
	return 0
}