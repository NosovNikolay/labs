#include"lib.h"
unsigned char test_mass_remove()
{

	char is_success = 1;
	printf("Test running\"%s\"...\n",__FUNCTION__);
	backpack_t **backpack_array;
	backpack_t add_element;
	
	if (create_arr(&backpack_array, SIZE) == 0)
		return 1;
	
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
		
	remove_backpack(backpack_array, 0);
	
	is_success &= !strcmp((*backpack_array)->brand_1.name, "");
	is_success &= !strcmp((*backpack_array)->brand_1.country, "");
	is_success &= !strcmp((*backpack_array)->laptop_compartment, "");
	is_success &= !strcmp((*backpack_array)->color, "");
	is_success &= !strcmp((*backpack_array)->appointment, "");
	is_success &= (*backpack_array)->volume == 0;	
	
	free_arr(&backpack_array,SIZE);
	
	if(!is_success)
	{
		printf("Test failed %s\n", __FUNCTION__);
		return 0;
	}
	return 1;
}

unsigned char test_mass_insert(void)
{
	unsigned char is_success = 1;

	printf("Test running\"%s\"...\n",__FUNCTION__);
	backpack_t **backpack_array;
	backpack_t add_element;
	
	if (create_arr(&backpack_array, 10) == 0)
		return 1;
	
	/*Fill the object, that will be added*/
	strcpy(add_element.brand_1.name, "abibas");
	strcpy(add_element.brand_1.country, "Tajikistan");
	strcpy(add_element.laptop_compartment, "YEA");
	strcpy(add_element.color, "BLACK");
	strcpy(add_element.appointment, "Gaming");
	add_element.volume = 15;
		
	/*Add elements*/
	add_backpack(backpack_array, 0, &add_element);
	
	is_success &= !strcmp((*backpack_array)->brand_1.name, "abibas");
	is_success &= !strcmp((*backpack_array)->brand_1.country, "Tajikistan");
	is_success &= !strcmp((*backpack_array)->laptop_compartment, "YEA");
	is_success &= !strcmp((*backpack_array)->color, "BLACK");
	is_success &= !strcmp((*backpack_array)->appointment, "Gaming");
	is_success &= (*backpack_array)->volume == 15;
	
	free_arr(&backpack_array,SIZE);
	
	if(!is_success)
	{	
		printf("Test failed %s\n", __FUNCTION__);
		return 0;
	}
	return 1;
}

unsigned char test_reduce()
{
	printf("Test running\"%s\"...\n",__FUNCTION__);
	char string_cut[15];
	strcpy(string_cut, CUT_OFF);
	reduce(string_cut, FROM, TO);
	if(strcmp(string_cut, "Salam!"))
	{
		printf("Test failed %s\n", __FUNCTION__);
		return 0;
	}
	else
	return 1;
}

unsigned char test_insert()
{
	printf("Test running\"%s\"...\n",__FUNCTION__);
	char str_res[20];
	char str_insert[15];
	strcpy(str_res, BASE);
	strcpy(str_insert, INSERT);
	insert(str_res, str_insert, POSITION);
	if(strcmp(str_res, "I want some pizza!"))
	{
		printf("Test failed %s\n", __FUNCTION__);
		return 0;
	}
	else
	return 1;
}

int main()
{
	unsigned char is_success = 1;
	is_success &= test_insert();
	is_success &= test_reduce();
	is_success &= test_mass_insert();
	is_success &= test_mass_remove();
	if(is_success)
		printf("\nSuccessfuly!\n");
	else
		printf("\nOh shit, it doesn't work!\n");
}

