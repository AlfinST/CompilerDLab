#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;
	
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
}
 
int main(){
	char ch, buffer[500],opbuf[3],operators[11][3] = {"+","-","*","/","++","!","=","==",">=","<=","!="};
	FILE *fp,*bp;
	int i,j=0;
	int bc=0,opflag=1;
	char nc,dummy,opstr[3]="";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////---Opens File Here
	fp = fopen("./program.c","r");
	
	if(fp == NULL){
		printf("error whil3 e opening the file\n");
		exit(0);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////---Reads the next Character 
	while((ch = fgetc(fp)) != EOF)
	{	strcpy(opstr,"");	
		//printf("'%c' is the character\n",ch);
		//bp = clone(fp);
		bp = fp;
		opstr[0]=ch;
		opstr[1]='\0';
			for(i = 0; i < 8; i++)
				if (!strcmp(opstr,operators[i]))//(ch == operators[i][0]) 
				{
					//opbuf[bc++]=ch;
					nc=fgetc(bp);
					opstr[1]=nc;
					opstr[2]='\0';
					for(i = 0; i < 10; i++)
						if(!strcmp(opstr,operators[i]))//(nc == operators[i][0]) 
						{
							//opbuf[bc]=ch;
							opbuf[++bc]='\0';
						}
						else
							opbuf[bc]='\0';
						printf("%s is operator\n",opstr);
				}

			for(i = 0; i < 11; ++i)//////////////////////////////////////////////////--Checks if Operator
	   		{
	   			if(!strcmp(opbuf,operators[i]))
	   				printf("%s is operator\n\n", ch);
	   		}
	   		bc=0;
	   		///////////////////////////////////////////////////////////////////////-- Adds to Buffer
	   		if (ch=='\"')
	   		{
	   			dummy=fgetc(fp);
	   			printf("Ignoring cause String\n\n%c",dummy);
	   			while(dummy !='\"')
	   				{
	   					dummy=fgetc(fp);
	   					printf("%c",dummy );
	   				}	
	   			printf("\nDone Ignoring\n\n");
	   		}

	   		if(isalnum(ch) || ch == '_')
	   		{
	   			buffer[j++] = ch;
	   		}
	   		else if((ch == ' ' || ch == '\n'|| ch == '\t'|| ch =='(') && (j != 0)){///////////////////////-- decides end of buffer
	   				buffer[j] = '\0';
	   				j = 0;
	   				   				
	   				if(isKeyword(buffer) == 1)///////////////////////////////////-- Checks if Keyword
	   					printf("%s is keyword\n\n", buffer);
	   				else
	   					printf("%s is indentifier\n\n", buffer);/////////////-Else Indentifoer
	   		}
	
   		
	}
	
	fclose(fp);
	
	return 0;
}