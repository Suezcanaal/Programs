#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top =0, *newNode  ,*temp;

void push(int x)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data =x;
    newNode -> next = top;
    top = newNode;
}
void pop()
{
    temp= top;
    top = top->next;
    free(temp);
}
void display()
{
    temp=top;
    while(temp!=NULL)
    {
        printf(" %d\n",temp->data);
        temp = temp->next;
    }
}
void peek()
{
    printf("%d",top->data);
}

int main()
{
    int ch;
    int x;
    while (1)
    {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\nEnter ur choice\n");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:
            printf("Enter  number \n");
            scanf("%d",&x);
            push(x);
            break;

            case 2:
                pop();
                break;
            case 3:
                peek();
                break;

            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
                default :printf("Invalid choice\n");


        }

    }
    return 0;
}
