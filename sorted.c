#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[30];
    struct Node *next;
};

struct Node *head = NULL, *newNode, *temp,*prev;

void insert(char x[30])
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, x);
    newNode->next = NULL;

    if (head == NULL || strcmp(newNode->data, head->data) < 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && strcmp(newNode->data, temp->next->data) > 0)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete()
{
    char value[50];
    temp=head;
    printf("Enter the name to be deleted = ");
    scanf("%s",value);
    while (temp != 0)
    {
        if (strcmp(temp->data,value) == 0)
        {
            if (temp == head)
            {
                head=head->next;
                free(temp);
                return;
            }
            else if (temp->next == 0)
            {
                prev->next=0;
                free(temp);
                return;
            }
            else
            {
            prev->next=temp->next;
            free (temp);
            return;
            }
        }
        prev=temp;
        temp=temp->next;
    }
}

void display()
{
    temp = head;
    
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch;
    char value[50];

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the Name: ");
            scanf("%s", value);
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
