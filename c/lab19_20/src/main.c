#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "data.h"
int get_choise()
{
	int tmp;
	scanf("%d", &tmp);
	if(tmp > 8 || tmp < 0)
		return INCORRECT;
	return tmp;
}

void print_options()
{
	printf("Enter the number from 1 to 8:\n"
	" 1. Push an element to the end of the list\n"
	" 2. Find an element using position\n"
	" 3. Remove an element in the list\n"
	" 4. Print all elements of the list\n"
	" 5. Sort list elements by volume of backpack\n"
	" 6. Write the list to file\n"
	" 7. Read thi list from file\n"
	" 8. Exit\n\n");
}
int main()
{
	time_now();
	
	print_func_name(__FUNCTION__);

	/*List with backpacks*/
	dllist_t *list = create_dllist();
	
	/*For getting backpack from user*/
	backpack_t *element;
	
	int chose;

	/*To delete an element*/
	size_t pos;

	char filename[100];
	
	/*Get time*/
	double star = start();

	do {
		do {
			print_options();
			if ((chose = get_choise()) == INCORRECT)
				printf("You need to enter correct number\n");
		} while (chose == INCORRECT);
		switch (chose) {
		case PUSH:
			printf("Enter the backpack fields in the next order:\n"
			"Brand country//Brand//Appointment//Color//Lapton compartment//Volume\n");
			element = get_backpack_from_user();
			push_dllist(list, element);
			free(element);
			break;
		case FIND:
			scanf("%lu", &pos);
			find_in_dllist(list, pos);
			break;
		case REMOVE:
			printf("Enter the position of the element to be removed: ");
			scanf("%lu", &pos);
			remove_from_dllist(list, pos);
			break;
		case PRINT:
			print_dllist(list);
			break;
		case SORT:
			sort_by_volume_dllist(list);
			break;
		case FWRITE:
			printf("Enter the filename: ");
			scanf("%s", filename);
			write_to_file(list, filename);
			break;
		case FREAD:
			printf("Enter the filename: ");
			scanf("%s", filename);
			read_from_file(list, filename);
			break;
		}
	} while (chose != EXIT);

	free_dllist(&list);

	printf("Thanks for using program!\n");
	
	stop(star);

	return 0;
}
