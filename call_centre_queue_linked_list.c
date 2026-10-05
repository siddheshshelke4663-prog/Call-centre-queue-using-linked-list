#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int callID;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void addCall()
{
    int id;
    struct Node *newNode;

    printf("\nEnter Call ID: ");
    scanf("%d", &id);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->callID = id;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Call added successfully!\n");
}

void attendCall()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }

    temp = front;

    printf("\nCall %d is being attended.\n", temp->callID);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void displayCalls()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }

    temp = front;

    printf("\nWaiting Calls: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->callID);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CALL CENTRE QUEUE =====\n");
        printf("1. Add Call\n");
        printf("2. Attend Call\n");
        printf("3. Display Calls\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addCall();
                break;

            case 2:
                attendCall();
                break;

            case 3:
                displayCalls();
                break;

            case 4:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
