#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
        int pno,wt,bt,tat;
		
        struct node *next;
        };
typedef struct node *queue;

void enqueue(int pn,int b,queue rear){
        queue temp,t;
        temp=(queue)malloc(sizeof(queue));
        temp->pno=pn;
        temp->bt=b;
        t=rear;
                while(t->next)
             t=t->next;
            temp->next=t->next;
            t->next=temp;
        }
void dequeue(queue rear){
        queue temp;
        temp=(queue)malloc(sizeof(queue));
        temp=rear;
        rear=rear->next;
        free(temp);
}

void fcfs(queue rear){
	   printf("\n--------------------------------------------------------------------------\n");
            printf("\nProcess\t|Burst Time\t|Waiting Time\t|Turnaround Time\n");
               printf("\n--------------------------------------------------------------------------\n");
        queue t;
        t=rear;
        t->bt=0;
        t->wt=0;
        int a=0;
        int b=0,s;int i1,j1,k1;
        i1=0;j1=0;k1=0;s=0;
         int pn[20],bti[20],pr[20];
        float c=0,d=0,e=0;
		while(t->next)
        {
                a+=t->bt;
                b=a+t->next->bt;
            t->wt=0;
        t->wt+=a;
        e+=a;
        c+=b;
     
        printf("\nP%d\t|\t%d\t|\t%d\t|\t%d",t->next->pno,t->next->bt,a,b);
        pn[i1]=t->next->pno;  bti[j1]=t->next->bt; pr[k1]=b; 
           i1++;  j1++; k1++;  s++;
           printf("\n--------------------------------------------------------------------------\n\n\n");
        dequeue(t);
        t=t->next;
        d++;
        }
        dequeue(t);
        float n=e/d;
        float m=c/d;
        j1=0;
		 printf("\n\n\nGANTT CHART\n\n");
		  printf("-----------------------------------------------\n");
		for(i1=0;i1<s;i1++)
        {  
        	printf("|  P%d(%d) ",pn[i1],bti[j1]);
                    
        j1++;
        
    }
    	  printf("|\n-----------------------------------------------\n");
    	for(k1=0;k1<s;k1++)
		{
			printf("         %d",pr[k1]);
		  }  
        
        printf("\n\n-------------------------------------------------------");
                printf("\nAverage waiting time\t|\tAverage turnaround time\n");
                  printf("-------------------------------------------------------\n");
                printf("%f\t\t|\t%f\n",n,m);
                 printf("-------------------------------------------------------\n");
}
void sjf(queue rear){
        queue t,temp;
        temp=rear;
        int n,i;
        n=count(rear);
    for(i=0;i<n;i++){
        t=rear;
        while(t->next)
        {
        if(t->bt>t->next->bt){
                temp->bt=t->bt;
                t->bt=t->next->bt;
 t->next->bt=temp->bt;
                temp->pno=t->pno;
                t->pno=t->next->pno;
                t->next->pno=temp->pno;
                        }
                t=t->next;
    }
        }
        t=rear;
        fcfs(t);
       }
       int count(queue rear){
        queue t;
        t=rear;
        int c=0;
 while(t->next){
         c++;
         t=t->next;}
        return c;
}
       void display(queue rear){
        queue t=rear->next;
        while(t){
                printf("%d\t",t->pno);
                printf("%d\n",t->bt);
                t=t->next;
        }
        printf("\n");
}
int main(){
        int choice;
        
        while(1){
        	printf("~CPU SCHEDULING~\n");
        printf("\n~1.FCFS scheduling~\t~2.SJF scheduling~\t3.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        {	queue rear=(queue)malloc(sizeof(queue));
        rear->next=NULL;
        int p,n,i;
        int b;	
							printf("Enter no of processes\n");
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
{
			 printf("Enter process no:\n");
                                scanf("%d",&p);
                                printf("Enter burst time:\n");
                                scanf("%d",&b);
                                enqueue(p,b,rear);}
                                 fcfs(rear);
                                break;
                        }
                case 2:
                         {	queue rear=(queue)malloc(sizeof(queue));
        rear->next=NULL;
        int p,n,i;
        int b;			
						 			printf("Enter no of processes\n");
                        scanf("%d",&n);
                        for(i=0;i<n;i++)
{
								                                printf("Enter process no:");
                                scanf("%d",&p);
                                printf("Enter burst time:");
                                scanf("%d",&b);
                                enqueue(p,b,rear);}
                                sjf(rear);
                                break;
                        }
                case 3:
                        {printf("exited succesfully!");
                        exit(0);
                }
        }
 }
 return 0;
}
