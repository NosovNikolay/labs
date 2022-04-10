#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

dllist_t *create_dllist()
{
	dllist_t *tmp = (dllist_t *)malloc(1);
	tmp->head = tmp->tail = NULL;
	tmp->size = 0;
	return tmp;
}

void free_dllist(dllist_t **list)
{
	if (list != NULL && *list != NULL && (*list)->size != 0)
	{
		/* Get last element */
		element_t *iter = (*list)->tail;
		/* Delete all elements */
		while (iter->prev != NULL)
		{
			iter = iter->prev;
			free(iter->next);
		}
		free(iter);
		free(*list);
		*list = NULL;
	}
	return;
}

void write_to_file(dllist_t *list, const char *filename)
{
	print_func_name(__FUNCTION__);
	FILE *ptr;
	if ((ptr = fopen(filename, "w")) == NULL)
	{
		printf("Can't open file");
		return;
	}
	element_t *iter = list->head;

	do
	{
		fprintf(ptr, "%s %s %s %s %s %u\n",
				iter->data.brand_1.country, iter->data.brand_1.name,
				iter->data.appointment, iter->data.color,
				iter->data.laptop_compartment, iter->data.volume);
	}while ((iter = iter->next) != NULL);
	fclose(ptr);
}

void read_from_file(dllist_t *list, const char *filename)
{
	print_func_name(__FUNCTION__);

	backpack_t *element;
	/*File for read*/
	FILE *ptr;

	if ((ptr = fopen(filename, "r")) == NULL)
	{
		printf("Can't open file");
		return;
	}

	if ((element = malloc(sizeof(backpack_t))) == NULL)
	{
		printf("Can't allocate memory");
		fclose(ptr);
		return;
	}

	while (fscanf(ptr, "%s %s %s %s %s %d\n", element->brand_1.country,
				  element->brand_1.name,
				  element->appointment, element->color,
				  element->laptop_compartment, &element->volume) == 6)
	{
		push_dllist(list, element);
	}
	fclose(ptr);
	free(element);
}
void print_dllist(dllist_t *list)
{
	print_func_name(__FUNCTION__);
	if (list == NULL)
	{
		printf("Nothing to print\n");
		return;
	}

	element_t *iter = list->head;

	while (iter != NULL)
	{
		printf("{{\"%s\", \"%s\", \"%s\"} \"%s\", \"%s\", %3u\n",
			   iter->data.brand_1.country, iter->data.brand_1.name,
			   iter->data.appointment, iter->data.color,
			   iter->data.laptop_compartment, iter->data.volume);
		iter = iter->next;
	}
}

element_t *find_in_dllist(dllist_t *list, size_t pos)
{
	print_func_name(__FUNCTION__);
	if (list == NULL || pos > list->size)
	{
		printf("Can't find\n");
		return NULL;
	}
	element_t *iter = list->head;

	while (iter != NULL && pos-- != 0)
		iter = iter->next;

	return iter;
}

void remove_from_dllist(dllist_t *list, size_t pos)
{
	print_func_name(__FUNCTION__);
	element_t *element;

	if (list == NULL)
	{
		printf("Can't remove\n");
		return;
	}

	if (list->size == 0 || pos >= list->size)
		return;
	element = find_in_dllist(list, pos);

	if (list->size == 1)
		list->head = list->tail = NULL;
	else if (pos == 0)
	{
		element->next->prev = NULL;
		list->head = element->next;
	}
	else if (pos == list->size - 1)
	{
		element->prev->next = NULL;
		list->tail = element->prev;
	}
	else
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	free(element);
	list->size--;
}

void push_dllist(dllist_t *list, backpack_t *element)
{
	print_func_name(__FUNCTION__);
	element_t *prev;

	element_t *insert;

	if (!list || !element)
		return;

	if (list->tail == NULL)
	{
		insert = list->head = list->tail = malloc(sizeof(element_t));
		if (list->head == NULL)
			return;

		insert->prev = insert->next = NULL;

		memcpy(&insert->data, element, sizeof(backpack_t));
	}
	else
	{
		prev = list->tail;

		insert = prev->next = malloc(sizeof(element_t));
		if (prev->next == NULL)
		{
			return;
		}

		insert->prev = prev;
		insert->next = NULL;

		list->tail = insert;

		memcpy(&insert->data, element, sizeof(backpack_t));
	}
	list->size++;
}

void sort_by_volume_dllist(dllist_t *list)
{
	print_func_name(__FUNCTION__);

	element_t *iter;

	element_t *left;
	/* minimal volume*/
	element_t *min;

	if (list->size <= 1)
		return;

	for (left = list->head; left != list->tail; left = min->next)
	{
		/* from tail to head*/
		min = iter = list->tail;

		/*the lowest*/
		while (iter != left)
		{
			/* if both are the same */
			if (min->data.volume >= iter->prev->data.volume)
				min = iter->prev;
			/*to the next element */
			iter = iter->prev;
		}

		/* if already at position - contunie*/
		if (min == left)
			continue;

		/* for the first element*/
		if (left == list->head)
			list->head = min;
		/* for the last */
		if (min == list->tail)
			list->tail = left;

		/*if stand by side and point at each other */
		iter = min->next;
		min->next = (left->next == min) ? left : left->next;
		left->next = iter;

		iter = min->prev;
		min->prev = left->prev;
		left->prev = (min->prev == left) ? min : iter;

		min->next->prev = min;
		if (min->prev != NULL)
			min->prev->next = min;

		left->prev->next = left;
		if (left->next != NULL)
			left->next->prev = left;
	}
}