#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BASE "I want some!" 
#define INSERT " pizza" 
#define POSITION 11 
#define CUT_OFF "Salam Aleikum!"
#define FROM 5 
#define TO 12 
#define SIZE 2
/**
* Struct with information about a brand of the backpack
*/
typedef struct brand
{
	char name[15];
	char country[15];
}brand_t;
/**
* Struct with information about a backpack
*/
typedef struct backpack
{
	char laptop_compartment[4];
	char color[10];
	int volume;
	brand_t brand_1;
	char appointment[10];
}backpack_t;

/**
* Function inserts one string into another
*
* @param base - 1-st string
* @param insert - 2-nd string
* @param pos - position where the string will be inserted
*/
void insert(char *base, char *insert, size_t pos);

/**
* Function removes a part of string
*
* @param base - string
* @param begin - where the deletion will come from
* @param end - to where will the deletion take place
*/
void reduce(char *base, size_t begin, size_t end);

/**
* Function adds an element to the massive 
*
* @param backpack - massive
* @param i - position 
* @param add_element - element
*/
void add_backpack(backpack_t **backpack, size_t i, backpack_t *add_element);

/**
* Function removes an element from massive
*
* @param backpack - massive
* @param i - position
*/
void remove_backpack(backpack_t **backpack, size_t i);

/**
* Function print the massive to terminal
*
* @param backpack - massive
* @param size - size of massive
*/
void print_arr(backpack_t **backpack, size_t size);

/**
* Function frees the memory where the array was
*
* @param backpack - massive
* @param size - size of massive
*/
void free_arr(backpack_t ***backpack, size_t size);

/**
* Function allocates memory for the array and its elements
*
* @param backpack - pointer to pointer to pointer -______-
* @param size - size of massive 
* @return 1 - good, 0 - bad
*/
char create_arr(backpack_t ***backpack, size_t size);
#endif
