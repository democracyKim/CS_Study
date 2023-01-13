#include "dynamic_array.h"

array	*create_list(size_t max_num)
{
	array	*list;

	list = (array *)malloc(sizeof(array));
	if (!list)
		return (NULL);
	list->max_count = max_num;
	list->current_count = 0;
	list->next = calloc(sizeof(node), max_num);
	if (!list->next)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	return (list);
}

node	*get_node(array *list, size_t index)
{
	if (!list || index < 0 || list->current_count < index)
		return (NULL);
	return (list->next + index);
}

int is_full(array *list)
{
	return (list->current_count >= list->max_count);
}

int	insert_node(array *list, node new_node, size_t index)
{
	size_t	current;
	node	*dummy;

	current = list->current_count;
	if (!list || index < 0 || current < index)
		return (0);
	if (is_full(list))
	{
		dummy = list->next;
		list->next = calloc(sizeof(node), list->max_count * 1.5);
		if (!list->next)
			return (0);
		memcpy(list->next, dummy, sizeof(node) * list->max_count);
		list->max_count *= 1.5;
		free(dummy);
		dummy = NULL;
	}
	while (index < current)
	{
		*get_node(list, current) = *get_node(list, current - 1);
		current--;
	}
	*get_node(list, index) = new_node;
	list->current_count++;
	return (1);
}

int	remove_node(array *list, size_t index)
{
	size_t i;

	i = (list->max_count) - 1;
	if (index < 0 || ((list->current_count) <= index))
		return (0);
	while (index < i)
	{
		*get_node(list, index) = *get_node(list, index + 1);
		index++;
	}
	(*get_node(list, index)).data = 0;
	list->current_count--;
	return (1);
}

void	display_list(array *list)
{
	size_t	i;

	i = 0;
	printf("list : ");
	while (i < list->current_count)
	{
		printf("%d ", get_node(list, i)->data);
		i++;
	}
	printf("\n");
}

void	destroy_list(array *list)
{
	if (!list)
		return ;
	if (list->next)
		free(list->next);
	list->next = NULL;
	free(list);
	list = NULL;
}