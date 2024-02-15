#include <stdio.h>
#include<stdlib.h>
#define MAX 3

int items[MAX];
int front = -1;
int rear = -1;

void insert(int value);
void delete();

void display();

void insert(int value)
{
    if(rear == MAX -1)
    {
        printf(" is FUll\n");
    }
    else
    {
        if(front == -1)
        front ++;
        
        rear = rear +1;
        items[rear]=value;
        printf("Caller id added is %d",items[rear]);
    }
}

void delete()
{
    if(rear == -1)
    {
    printf("Que is empty");
    }
    else
    {
        printf("Deleted caller id is %d",items[front]);
        
        front ++;
    }
    if(front > rear)
    front = rear = -1;
}

void display()
{
    if(rear == -1)
    {
        printf("que is empty");
    }
    else
    {
        for (int i=front ;i <= rear;i++)
        {
            printf("[%d] = %d",i,items[i]);
        }
    }
}

int main()
{
    int ch; 
    
   
   
   while(1)
   {
       printf("Enter the choice \n1.insert\n2.delete\n3.display\n4.exit\nEnter your choice : ");
        scanf("%d",&ch);
       switch(ch)
       {
           case 1 :
           int value;
           printf("\nEnter the value\n");
           scanf("%d",&value);
           insert(value);
           break;
           
           case 2:
           delete();
           break;
           
           case 3 : 
           display();
           break;
           
           case 4 : 
           exit (0);
         
          default :
          printf("Invalid choice ");
          
       }
   }   

    return 0;
}



