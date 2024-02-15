#include<stdlib.h>
#include <stdio.h>
#define MAX 3

struct circularque
{
    int data;
};

struct circularque Que[MAX];
int front = -1;
int rear = -1;

void insert(int value);
void delete();
void display();

void insert(int value)
{
    if ((rear == MAX - 1 && front == 0) || (rear + 1 == front))
    {
        printf("Queue is full\n");
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    Que[rear].data = value;
}

void delete()
{
    if (rear == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    int value = Que[front].data;
    if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("Deleted value is %d\n", value);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("Que[%d] = %d\n", i, Que[i].data);
        }
        printf("Que[%d] = %d\n", i, Que[i].data);
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
