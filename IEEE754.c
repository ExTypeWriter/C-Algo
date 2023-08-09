#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_stack
{
     char string;
     struct t_stack *next;
};

void push(struct t_stack **top, char stream);
void pop(struct t_stack **top);
char peek(struct t_stack **top);

int main()
{
     struct t_stack *stackForward = NULL, *stackBackward = NULL;
     char buffer[10000] = {'\0'};
     char return_value;
     char *token;

     fgets(buffer, 10000, stdin);
     if (buffer[strlen(buffer) - 1] == '\n')
     {
          buffer[strlen(buffer) - 1] = '\0';
     }
     int i = 0;
     while (i < strlen(buffer))
     {
          push(&stackBackward, buffer[i]);
          i++;
     }

     while (stackBackward != NULL)
     {
          push(&stackForward, peek(&stackBackward));
          pop(&stackBackward);
     }
     while (stackForward != NULL)
     {
          return_value = peek(&stackForward);
          printf("%c", return_value);
          push(&stackBackward, return_value);
          pop(&stackForward);
     }
     if (strlen(buffer) % 2 == 0)
     {
          stackBackward = stackBackward->next;
     }
     while (stackBackward != NULL)
     {
          printf("%c", peek(&stackBackward));
          pop(&stackBackward);
     }
     printf("\n");
     return 0;
}

void push(struct t_stack **top, char stream)
{
     struct t_stack *newNode = (struct t_stack *)calloc(1, sizeof(struct t_stack));
     newNode->string = stream;
     if (*top == NULL)
     {
          newNode->next = NULL;
          *top = newNode;
     }
     else
     {
          newNode->next = *top;
          *top = newNode;
     }
}

void pop(struct t_stack **top)
{
     struct t_stack *node_to_free = NULL;
     if (*top == NULL)
     {
          printf("STACK UNDERFLOW\n");
          return;
     }
     node_to_free = *top;
     *top = (*top)->next;
     free(node_to_free);
}

char peek(struct t_stack **top)
{
     if (*top != NULL)
     {
          return (*top)->string;
     }
}
