# What is Arrays and Dynamic Arrays?
Arrays are the most simple data structure. You can restore data by using arrays like a palette containing various colors. 

Dynamic arrays are similar to Arrays, but you can enlarge the size of spaces. It is more comfortable than Arrays if you don't know the size. But the con is time complexity because you must copy each data to the newly allocated spaces when you make more spaces. 
## header
```c
typedef struct node_type {
	int	data;
} node;

typedef struct array_type {
	size_t	max_count;
	size_t	current_count;
	node	*next_node;
} array;
```
I thought that counting could naturally be regarded as a positive number, so I used the size_t type for counting variables. 

## list of functions
### create_list
Make 'max_num' rooms for containing data, using structure type. Create a new list by using malloc and initialize each member variable. To initialize the member of the structure, you can use 'calloc' instead of directly accessing member variables.  

When you free something, put NULL into the something. It protects you from accessing something even after it was already released. 

```c
array	*create_list(size_t max_num)
{
	array	*list;

	list = (array *)malloc(sizeof(array));
	if (!list)
		return (NULL);
	list->max_count = max_num;
	list->current_count = 0;
	list->next_node = calloc(sizeof(node), max_num);
	if (!list->next_node)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	return (list);
}
```

### get_node
Get node by index. Just bring the 'start node + index' address. If you can't get a typical result, return NULL. 
```c
node	*get_node(array *list, size_t index)
{
	if (!list || index < 0 || list->current_count < index)
		return (NULL);
	return (list->next_node + index);
}
```

### is_full
If the array is full, return 1. You can put the conditional statement in the return value. When you do this, the conditional statement is regarded as the boolean type. So it returns 1 if the conditional statement is true and 0 if it is false. 
```c
int is_full(array *list)
{
	return (list->current_count >= list->max_count);
}
```

### insert_node
Insert node by index. Let's start with the palettes. There are red, green, and blue. Now, you want to insert yellow between red and blue. First, you should move blue to the next, green to the next, and squeeze yellow on the palette, which was the position of green. But if the palette is full, you should buy a bigger one and move each color to the new one. 

Dynamic arrays are the same as the palette. Suppose you insert into the array the position of the index. You should move the index value from one end to the next. And if the node is full, you should lengthen the array and copy every value.

```c
int	insert_node(array *list, node new_node, size_t index)
{
	size_t	current;
	node	*dummy;

	current = list->current_count;
	if (!list || index < 0 || current < index)
		return (0);
	if (is_full(list))
	{
		dummy = list->next_node;
		list->next_node = calloc(sizeof(node), list->max_count * 1.5);
		if (!list->next_node)
			return (0);
		memcpy(list->next_node, dummy, sizeof(node) * list->max_count);
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
```

### remove_node
Insert node by the index. From the index node to the end node, move the next node to the current node. 

```c
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
```

### display_list
Display the all nodes containing data. 
```c
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
```

### destroy_list
Destroy the list and all nodes. If the list is not allocated, finish the function. 
```c
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
```