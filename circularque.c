#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int items[MAX];
int front = -1;
int rear = -1;

void insert(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full\n");
    }
    else if (rear == -1 || front == -1)
    {
        rear = front = 0;
        items[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        items[rear] = x;
    }
}

void deleteElement()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (front == rear)
        {
            // Reset front and rear when the last element is dequeued
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int tempFront = front;
        while (tempFront != rear)
        {
            printf(" %d \n", items[tempFront]);
            tempFront = (tempFront + 1) % MAX;
        }
        printf(" %d \n", items[rear]);
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
            deleteElement();
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
