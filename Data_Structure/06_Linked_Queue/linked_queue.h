#ifndef LINKED_QUEUE_H
# define LINKED_QUEUE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node {
	int			data;
	struct node	*next;
} node;

typedef struct list {
	node	*headnode;
	node	*rearnode;
} queue;

queue	*create_queue();
node	*create_new_node(int data);
int		enqueue(queue *list, int data);
int		dequeue(queue *list);
void	display_queue(queue *list);
void	destroy_queue(queue **list);

#endif