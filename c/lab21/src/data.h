#define PUSH 1 
#define FIND 2
#define REMOVE 3 
#define PRINT 4 
#define SORT 5 
#define FWRITE 6 
#define FREAD 7 
#define EXIT 8 
#define INCORRECT 0 
#ifndef DATA
#define DATA

#include <time.h>
/**
* Struct with information about brand
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
 * Function takes information from the user about a backpack 
 * @return structure pointer 
 */
backpack_t  *get_backpack_from_user();
/**
 * Function prints current time and date 
 */
void time_now();
/**
 * Function detects the start time of the program
 * @return time of the start
 */
double start();
/**
 * Function prints execution time
 */
void stop(double start);
/**
 * Function prints name of current func
 */
void print_func_name(const char *func_name);
#endif 


