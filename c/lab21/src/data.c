
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

	if ((tmp = calloc(1, sizeof(backpack_t))) == NULL) {
		printf("[ERROR/%s]: Can't allocate memory for the backpack\n",
		       __FUNCTION__);
		return NULL;
	}

	scanf("%s %s %s %s %s %d", tmp->brand_1.country, 
				tmp->brand_1.name,
			    tmp->appointment, tmp->color,
			    tmp->laptop_compartment, &tmp->volume);

	return tmp;
}

