#include <stdlib.h>
#include <stdio.h>
 
#define snapd(arg) printf(#arg " = %d\n", arg);
#define snapf(arg) printf(#arg " = %f\n", arg);
 
struct fifo 
{
    int data;
    struct fifo *next;
    struct fifo *prev;
};
 
void lpush(struct fifo **st, struct fifo **en,int value)
{
    struct fifo *newnode;
 
    if (*st == NULL)
        {
        newnode = (struct fifo *)malloc(sizeof(struct fifo));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        *st=newnode; *en = newnode;
        return;
        }
 
    newnode = (struct fifo *)malloc(sizeof(struct fifo));
    newnode->data = value;
    newnode->next = *st;
    (*st)->prev = newnode;
    *st = newnode;
    newnode->prev = NULL;
    return ;
 
}

void rpush(struct fifo **st, struct fifo **en,int value)
{
    struct fifo *newnode;
 
    if (*en == NULL)
        {
        newnode = (struct fifo *)malloc(sizeof(struct fifo));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        *st=newnode; *en = newnode;
        return;
        }
 
    newnode = (struct fifo *)malloc(sizeof(struct fifo));
    newnode->data = value;
    newnode->next = *en;
    (*en)->next = newnode;
    *en = newnode;
    newnode->next = NULL;
    return ;
 
}
 
void rpop(struct fifo **st, struct fifo **en)
{
    struct fifo *top;
 
    if (*st == NULL && *en == NULL)
        {
        printf("The stack is empty!\n");
        return ;
        }

    top = *en;       
    if (*st == *en) {
        *st = NULL;
        *en = NULL;
        free(top);
        return;
    }
    

    *en = (*en)->prev;
    (*en)->next=NULL;
    free(top);
    return ;
 
}

void lpop(struct fifo **st, struct fifo **en)
{
    struct fifo *top;
 
    if (*st == NULL && *en == NULL)
        {
        printf("The stack is empty!\n");
        return ;
        }

    top = *st;       
    if (*st == *en) {
        *st = NULL;
        *en = NULL;
        free(top);
        return;
    }
    

    *st = (*st)->next;
    (*st)->prev=NULL;
    free(top);
    return ;
 
}

void clear(struct fifo **st, struct fifo **en)
{
    struct fifo *top;
    
    while (!(*st == NULL && *en == NULL)) {   
        top = *st;       
        if (*st == *en) {
            *st = NULL;
            *en = NULL;
            free(top);
        } else {
            *st = (*st)->next;
            (*st)->prev=NULL;
            free(top);       
        }
    }

 
}
 
void printstack(struct fifo *st)
{
    if (st == NULL)
        {
        printf("The stack is empty!\n");
        return;
        }
 
    do
        {
        printf("%d ", st->data);
        st = st->next;
        }
    while (st);
    printf("\n");
}
 
 
 
int main (int argc, char *argv[])
{
 
    struct fifo *st = NULL, *en = NULL;
    int command, value;
 
    printf("FIFO/Stack implementation with linked list.\n");
    printf("1 - lpush value.\n");
    printf("2 - rpush value.\n");
    printf("3 - lpop value.\n");
    printf("4 - rpop value.\n");
    printf("5 - clear stack.\n");
    printf("6 - print stack.\n");
    printf("7 - exit.\n");
    printf("Enter your command: ");
 
 
    for (;;)
        {
 
        scanf("%d", &command);
 
        switch (command)
            {
            case 1:
                {
                printf("Enter the value to push on to the stack: ");
                scanf("%d",&value);
                lpush(&st, &en, value);
                printf("Enter the next command: ");
                break;
                }

            case 2:
                {
                printf("Enter the value to push on to the stack: ");
                scanf("%d",&value);
                rpush(&st, &en, value);
                printf("Enter the next command: ");
                break;
                }
                
            case 3:
                {
                lpop(&st,&en);
                if (st != NULL) printf("The value is popped out of the stack\n");
                printf("Enter the next command: ");
                break;
                }

            case 4:
                {
                op(&st,&en);
                if (st != NULL) printf("The value is popped out of the stack\n");
                printf("Enter the next command: ");
                break;
                }

            case 5:
                {
                clear(&st,&en);
                printf("Enter the next command: ");
                break;
                }
  
 
            case 6:
                {
                printf("The contains of the stack is:\n");
                printstack(st);
                printf("====================================\n");
                printf("Enter the next command: ");
                break;
                }
 
            case 7:
                return 0;
 
            default:
                {
                printf("FIFO/Stack implementation with linked list.\n");
                printf("1 - lpush value.\n");
                printf("2 - rpush value.\n");
                printf("3 - lpop value.\n");
                printf("4 - rpop value.\n");
                printf("5 - clear stack.\n");
                printf("6 - print stack.\n");
                printf("7 - exit.\n");
                printf("Enter your command: ");
                break;
                }
 
            }
        }
}