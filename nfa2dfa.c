#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int a[10];
}sta;
int isIn(int *a,int key)
{
	for(int i=0;a[i]!=-1;i++)
	{
		if(key==a[i])
		{
			return 1;
		}
	}
	return 0;
}
void filter(int *a,int *x)
{	int i;
	a[0]=-1;
	for(i=0;x[i]!=-1;i++)
	{	a[i]=x[i];}
	a[i]=-1;
}
void group(int *a,int k)
{	int i;
	for(int i=0;a[i]!=-1;i++)
	{
		if(a[i]==k)
			return;
	}
	a[i]=k;
	a[i+1]=-1;
	
}
int isUnique(sta *a,sta *b[],int n){
	int i,j,*temp,f=0,len;
	if(a->a[0]==1 && a->a[1]==-1)
		return 0;
		
	for(i=0;i<n;i++)
	{		
		temp=b[i]->a;
		f=0;
		if(a->a[0]==-1 && temp[0]==-1)
			return 0;		
		for(j=0;a->a[j]!=-1;j++)
		{
			if(isIn(temp,a->a[j]))
				continue;
			f=1;
			break;
		}
		if(f==0){
			for(len=0;temp[len]!=-1;len++);
			if(len==j)
				return 0;
			
		}
	}
	return 1;
}
void main(){
	
	int i,j,temp,n,ni,k,rsize,head=0,tail=0,count=0,newind;
	sta final_mat[12][10],states[12],opresults[12][10],*sttemp,*q[100];
	char input_val[50];
	printf("Enter no. of states NFA: ");
	scanf("%d",&n);
	printf("Enter no. of i/p: ");
	scanf("%d",&ni);
	printf("Enter the alphabets: \n");
	for(i=0;i<ni;i++){
		scanf("\n%c",&input_val[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<ni;j++){
			printf("Enter outp[ut states of d(%d,%c)\n",i+1,input_val[j]);
			k=0;
			while(1){
				scanf("\n%d",&temp);
				if(temp==-1){
					final_mat[i][j].a[k]=-1;
					break;
				}
				final_mat[i][j].a[k]=temp;
				k+=1;				
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<ni;j++){
			printf("\nT(%d,%c) = (",i+1,input_val[j]);
			for(k=0;final_mat[i][j].a[k]!=-1;k++){
				printf("%d ",final_mat[i][j].a[k]);
			
			}
			printf(")");
		}
	}
	states[0].a[0]=1;
	states[0].a[1]=-1;
	for(i=0;i<ni;i++){
		//filer -1 at end
		filter(opresults[0][i].a,final_mat[0][i].a);
		if(isUnique(&(opresults[0][i]),q,tail)){
			q[tail]=&(opresults[0][i]);
			tail+=1;
		}
	}
	count=1;
	while(head<tail){
		//printf("%d %d\n",head,tail);
		sttemp=q[head];
		head+=1;
		filter(states[count].a,sttemp->a);		
		for(i=0;i<ni;i++){
			opresults[count][i].a[0]=-1;
			for(j=0;sttemp->a[j]!=-1;j++){
				newind=sttemp->a[j]-1;								
				for(k=0;final_mat[newind][i].a[k]!=-1;k++){					
					group(opresults[count][i].a,final_mat[newind][i].a[k]);
					
				}				
				
			}
						

		}
		count+=1;		
	}
	printf("\n\n");
	for(i=0;i<count;i++){		
		for(j=0;j<ni;j++){
			printf("\nT_new(");
			for(k=0;states[i].a[k]!=-1;k++){
				printf("%d,",states[i].a[k]);			
			}
			if(states[i].a[0]==-1){
				printf("dead ,");
			}		
			printf("%c) = ",input_val[j]);
			if(opresults[i][j].a[0]==-1){
				printf("dead ");
				continue;
			}
			printf("(");
			for(k=0;opresults[i][j].a[k]!=-1;k++){
				printf("%d ",opresults[i][j].a[k]);
			}
			printf(")");
		}
		
	}	
	
}
