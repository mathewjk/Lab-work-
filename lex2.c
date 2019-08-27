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
	char ch,ch1, buffer[15], operators[] = "+-*/%=",seperators[] = ",();";
	FILE *fp;
	int i,j=0;
	
	fp = fopen("source.txt","r");
	
	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
	
	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				  {
   				   	if(ch == '/')
   					{
   						ch1 = fgetc(fp);
   						if(ch1 == '/'|| ch1 == '*')  //checking for comment line
   							{
   							//printf("Comment line\n"); 
   							while(ch1 != '\n')  //iterating the entire comment line
							 	ch1 = fgetc(fp);  						
   							} 
   						else 	  
   							printf("%c\toperator\n", ch);	
   					}
   			else printf("%c\toperator\n", ch);
   				}
   		}	
   		if(ch=='#')
   		{	
   			ch=fgetc(fp);
   			if(ch=='d')
   			{	
   				printf("Macro definition\n");
   				while(ch == '\n') ch = fgetc(fp);
   			}
   			else printf("#\tPre-processor tag\n");
   		
   		}	
   		for(i = 0;i < 5; ++i){ //checking if seperator
   			if(ch == seperators[i])
   		         	printf("%c\tSeperator\n",ch);        				
   					}
   		
   		if(isalnum(ch) || ch=='.'){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n' || ch == '<' || ch == '>') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(isKeyword(buffer) == 1)
   					printf("%s\tkeyword\n", buffer);
   				else if(strcmp(buffer,"5.01")==0 || strcmp(buffer,"12.13")==0)
   					printf("%s\tConstant\n",buffer);
   				//else if(isdigit(buffer)) printf("%s\tConstant\n",buffer);
   				else
   				{	//if(isdigit(buffer[0])==1  || isalpha(buffer[0])==0)
   						//printf("Invalid Identifier\n");
   					//else	 
   						printf("%s\tidentifier\n", buffer);
   				}
   		
	}
	 }
	
	fclose(fp);
	
	return 0;
}
