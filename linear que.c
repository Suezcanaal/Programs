#include <stdio.h>
#include <stdlib.h>
#define MAX 18

int items[MAX];
int rear=-1;
int front =-1;

void insert(int x)
{
    if(rear == MAX-1)
    {
        printf("Que overflow\n");
    }
    else
    {
        if(front == -1)
            front=front+1;

        rear =rear +1;
        items[rear]=x;

    }
}
void delete()
{
    if(rear == -1)
    {
        printf("que Underflow\n");
    }
    else
    {
        front ++;
    }
}


void display()
{
   for(int i=front;i<=rear;i++)
   {
       printf(" %d \n",items[i]);
   }
}

int main()
{
 int ch;
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        int value;
        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
