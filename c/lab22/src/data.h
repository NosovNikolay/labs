#define TYPE_ERROR 1
#define BINARY_ERROR 2
#define DIGIT_ERROR 3

#define STRING_SIZE 256
#ifndef DATA
#define DATA
#include <time.h>
#include <regex.h>
/**
* Struct with information about brand
*/
typedef struct brand
{
	char name[STRING_SIZE];
	char country[STRING_SIZE];
}brand_t;
/**
* Struct with information about a backpack
*/
typedef struct backpack
{
	unsigned int laptop_compartment;
	char color[STRING_SIZE];
	int volume;
	brand_t brand_1;
	char appointment[STRING_SIZE];
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
/**
 * Function scans an element and checks for compliance
 * @param str - field of element
 * @param pattern - sample
 * @return 0 - found, 1 - not found
 */
int regex_scan_field(const char* str, const char* pattern);
/**
 * Function prints input problem
 * @param problem - number of the problem
 */
void print_error(int problem);
/**
 * Fucntion finds field with 2 or more words
 * @param current - pointer to element
 * @return 1 - found
 */
int has_two_words(backpack_t *current);
/**
 * Function find an element with field with 2 words
 * @param str - string 
 * @return 1 - found
 */
int regex_has_two_words(char *str);

#endif 


