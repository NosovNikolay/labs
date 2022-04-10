
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include "data.h"

void time_now()
{
#ifdef DEBUG
   long int ttime;
   ttime = time (NULL);
   printf ("Today is: %s\n",ctime(&ttime) );
#endif
	return;
}

double start()
{
#ifdef DEBUG
	double start = clock();
	return start;
#endif
	return 1;
}

void stop(double start)
{
#ifdef DEBUG
	double stop = (clock() - start)/1000;
	printf("Time :%.8f\n\n", stop);
#endif
	return;
}
void print_func_name(const char *func_name)
{
	#ifdef DEBUG
	printf("Now is working: %s function\n", func_name);
	#endif
	return;
}

backpack_t *get_backpack_from_user()
{
	backpack_t *tmp;

	char str[15];

	int result = 0;

	if ((tmp = calloc(1, sizeof(backpack_t))) == NULL) 
	{
		printf("[ERROR/%s]: Can't allocate memory for the backpack\n",
		       __FUNCTION__);
		return NULL;
	}
	printf("Enter country of brand: \n");
	do
	{
		scanf(" %10[^\n]s", tmp->brand_1.country); 
		if((result = regex_scan_field(tmp->brand_1.country, "^[A-Z][a-z_ ]*")) == 1)
			print_error(TYPE_ERROR);
		fflush(stdin);
	}while(result == 1);
	printf("Enter the name of the brand: \n");
	do
	{
		scanf("%s", tmp->brand_1.name); 
		if((result = regex_scan_field(tmp->brand_1.name, "^[A-Z][a-z_ ]*")) == 1)
			print_error(TYPE_ERROR);
		fflush(stdin);
	}while(result == 1);
	printf("Enter the color of the backpack: \n");
	do
	{
		scanf("%s", tmp->color); 
		if((result = regex_scan_field(tmp->color, "^[A-Z][a-z_ ]*")) == 1)
			print_error(TYPE_ERROR);
		fflush(stdin);
	}while(result == 1);
	printf("Enter the purpose of the backpack: \n");
	do
	{
		scanf("%s", tmp->appointment); 
		if((result = regex_scan_field(tmp->appointment, "^[A-Z][a-z_ ]*")) == 1)
			print_error(TYPE_ERROR);
		fflush(stdin);
	}while(result == 1);
	printf("Enter the volume of the backpack (two-digit) : \n");
	do
	{
		scanf("%s", str); 
		if((result = regex_scan_field(str, "[1-9][0-9]")) == 1)
		{	print_error(DIGIT_ERROR);
			fflush(stdin);
		}
		else 
			tmp->volume = (unsigned char)atoi(str);
	}while(result == 1);
	printf("Does the backpack contain laptop comparament :\n");
	do
	{
		scanf("%s", str); 
		if((result = regex_scan_field(str , "^[10]")) == 1)
		{	print_error(BINARY_ERROR);
			fflush(stdin);
		}
		else 
			tmp->laptop_compartment = (unsigned int)atoi(str);
	}while(result == 1);
	
	return tmp;
}
int regex_scan_field(const char* str, const char* pattern)
{	
	regex_t regex;
	
	int result = 0; 
	
	if(result = regcomp(&regex, pattern, REG_EXTENDED))
	{
		printf("Can't create regex");
		return result;
	}
	result = regexec(&regex, str, 0, NULL, 0);

	return result;
}
void print_error(int problem)
{
	switch (problem)
	{
	case BINARY_ERROR:
		printf("This field should contain only 1 or 0 (thue of false)!\n");
		break;
	case DIGIT_ERROR:
		printf("This  field should contain only two-digit number!\n");
		break;
	case TYPE_ERROR:
		printf("This field shoul contain only words, that start with capital letter!\n");
		break;
	default:
		printf("Try again : \n");
		break;
	}
}
int has_two_words(backpack_t *current)
{
	return regex_has_two_words(current->appointment)||
			regex_has_two_words(current->brand_1.country)||	
			regex_has_two_words(current->brand_1.name)||
			regex_has_two_words(current->color);
}

int regex_has_two_words(char *str)
{
	/* Шаблон выражения */
	regex_t regex;
	/* Код возврата */
	int return_code;

	return_code = regcomp(&regex, "^[^ ]+[ \t][^ ]+", REG_EXTENDED | REG_NOSUB);
	if (return_code != 0) {
		printf("[ERROR/%s]: function regcomp failed with code %d\n",
		       __FUNCTION__, return_code);
		return 1;
	}
	return_code = regexec(&regex, str, 0, NULL, 0);

	regfree(&regex);
	return !return_code;
}

