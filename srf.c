#include<stdio.h>
#include<string.h>

int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stack[15],act[10];

void check()
{
     strcpy(ac,"REDUCE TO E");
     for(z=0; z<c; z++)
       if(stack[z]=='i' && stack[z+1]=='d')
         {
           stack[z]='E';
           stack[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stack,a,ac);
           j++;
         }
         
     for(z=0; z<c; z++)
       if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E')
         {
           stack[z]='E';
           stack[z+1]='\0';
           stack[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stack,a,ac);
           i=i-2;
         }
         
     for(z=0; z<c; z++)
       if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E')
         {
           stack[z]='E';
           stack[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stack,a,ac);
           i=i-2;
         }
         
     for(z=0; z<c; z++)
       if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')')
         {
           stack[z]='E';
           stack[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stack,a,ac);
           i=i-2;
         }
         
}

void main()
{

      printf("Given Grammar\nE-E+E \nE-E*E \nE-(E) \nE-id"); //id fully is to be given
      printf("\nEnter input string: ");
      scanf("%s",&a);
      c=strlen(a);
      strcpy(act,"SHIFT-");
      puts("Stack \t Input \t Operation");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='i' && a[j+1]=='d')
           {
              stack[i]=a[j];
              stack[i+1]=a[j+1];
              stack[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s$\t%sid",stack,a,act);
              check();
           }
           
         else
           {
              stack[i]=a[j];
              stack[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%soperator",stack,a,act);
              check();
           }
           
       }
     if(stack[0]=='E' && stack[1]=='\0')
       	printf("\nAccepted\n");
     else
       	printf("\nRejected\n");

}

