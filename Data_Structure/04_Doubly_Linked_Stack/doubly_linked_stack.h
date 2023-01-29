#ifndef LINKED_STACK_H
# define LINKED_STACK_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node {
	int			data;
	struct node	*next;
	struct node	*prev;
} node;

typedef struct list {
	node	*top;
	node	*headnode;
} stack;

stack	*create_stack();
node	*create_new_node(int data);
int		push(stack *list, int data);
int		pop(stack *list);
void	display_stack(stack *list);
void	destroy_stack(stack **list);

#endif