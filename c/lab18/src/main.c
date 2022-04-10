#include"lib.h"
int main(void)
{
	/*Strings for task 1 and task 2*/
	char *str_res = malloc(strlen(BASE) + 1);
	
	char *str_insert = malloc(strlen(INSERT) + 1);

	char *string_cut = malloc(strlen(CUT_OFF) + 1);

	strcpy(str_res, BASE);
	strcpy(str_insert,INSERT);

	char* memory_check = (char*)realloc(str_res, strlen(BASE) + strlen(INSERT) + 1);
	if(memory_check == NULL)
	{
		free(memory_check);
		free(string_cut);
		free(str_insert);
		return 1;
	}
	else
		str_res = memory_check;
	
	printf("Task 1: %s + %s = ", str_res, str_insert);
	insert(str_res, str_insert, POSITION);
	printf("%s\n", str_res);
	
	free(str_res);
	free(str_insert);

	strcpy(string_cut, CUT_OFF);
	
	printf("Task 2: %s - all from %d to %d = ", string_cut, FROM, TO);
	reduce(string_cut, FROM, TO);
	printf("%s\n", string_cut);

	free(string_cut);

	/*Array and object for task 3*/
	backpack_t **backpack_array;
	backpack_t **backpack_array_add;
	backpack_t **backpack_array_rm;
	backpack_t add_element;
	
	if (create_arr(&backpack_array, SIZE) == 0)
		return 1;

	printf("\nNull massive: \n");
	print_arr(backpack_array, SIZE);
	
	/*Fill the object, that will be added*/
	strcpy(add_element.brand_1.name, "abibas");
	strcpy(add_element.brand_1.country, "Tajikistan");
	strcpy(add_element.laptop_compartment, "YEA");
	strcpy(add_element.color, "BLACK");
	strcpy(add_element.appointment, "Gaming");
	add_element.volume = 15;
		
	/*Add elements*/
	add_backpack(backpack_array, 0, &add_element);
	add_backpack(backpack_array, 1, &add_element);
	
	printf("\nMassive with 2 elements:\n");
	print_arr(backpack_array,SIZE);	
	
	if (create_arr(&backpack_array_rm, SIZE) == 0)
		return 1;
		
	if (create_arr(&backpack_array_add, SIZE + 1) == 0)
		return 1;
	
	for(int i = 0; i < SIZE ; ++i)
	{
		for(int j = 0; j < SIZE; ++j)
		backpack_array_add[i][j] = backpack_array[i][j];
	}
	
	free_arr(&backpack_array,SIZE);
	
	backpack_array = backpack_array_add;
	
	add_backpack(backpack_array, 2, &add_element);
	
	printf("\nMassive with 3 elements:\n");
	print_arr(backpack_array,SIZE + 1);
	
	for(int i = 0; i < SIZE - 1; ++i)
	{
		for(int j = 0; j < SIZE - 1; ++j)
		backpack_array_rm[i][j] = backpack_array[i][j];
	}
	
	remove_backpack(backpack_array, 2);
	
	printf("\nMassive with 2 elements but 3 slots:\n");
	print_arr(backpack_array,SIZE + 1);
	
	free_arr(&backpack_array,SIZE + 1);
	backpack_array = backpack_array_rm;
	
	printf("\nMassive with 2 slots and 1 element:\n");
	print_arr(backpack_array,SIZE);
	
	free_arr(&backpack_array,SIZE);
	
	return 0;
}
