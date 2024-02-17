#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[30];
    struct Node *next;
};

struct Node *head = NULL, *newNode, *temp;

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
    char storage[30];
    printf("Enter the Name to be deleted: ");
    scanf("%s", storage);

    while (temp != NULL && temp->next != NULL)
    {
        if (strcmp(storage, temp->next->data) == 0)
        {
            struct Node *de = temp->next;
            temp->next = temp->next->next;
            free(de);
            break;
        }
        temp = temp->next;
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
