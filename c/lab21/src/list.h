#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include "data.h"

typedef struct element element_t;
/**
 * Struct of element of double linked list
 */
struct element {
	backpack_t data;
	element_t *next;
	element_t *prev;
};
/**
 * Struct of double linked list
 */
typedef struct dllist {
	element_t *head;
	element_t *tail;
	size_t size;
} dllist_t;
/**
 * Function creates dllist
 * @return dllist pointer
 */ 
dllist_t *create_dllist();
/**
 * Function frees memory
 * @param list - pointer to pointer to list
 */
void free_dllist(dllist_t **list);
/**
 * Function finds an element is the list
 * @return pointer to an element
 * @param list - pointer to list
 * @param pos - index 
 */
element_t *find_in_dllist(dllist_t *list, size_t pos);
/**
 * Function adds an element to the list
 * @param list - list
 * @param element - element
 */
void push_dllist(dllist_t *list, backpack_t *element);
/**
 * Function removes an element from the list
 * @param list - list
 * @param pod - index
 */
void remove_from_dllist(dllist_t *list, size_t pos);
/**
 * Functoin writes list to the file 
 * @param list - list
 * @param filename - name of file
 */ 
void write_to_file(dllist_t *list, const char *filename);
/**
 * Function reads list from the file
 * @param list - list
 * @param filename - name of file
 */
void read_from_file(dllist_t *list, const char *filename);
/**
 * Function prints ddlist to the terminal
 * @param list - list
 */ 
void print_dllist(dllist_t *list);
/** 
 * Function sorts elements of list from lower to higher by volume
 * @param list - list
 */
void sort_by_volume_dllist(dllist_t *list);

#endif
