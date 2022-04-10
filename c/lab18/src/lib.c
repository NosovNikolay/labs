#include"lib.h"
void insert(char *base, char *insert, size_t pos)
{
	char *temp = calloc(strlen(base) + strlen(insert) + 1, sizeof(char));

	strncpy(temp, base, pos);
	strcat(temp, insert);
	strcat(temp, base + pos);
	
	temp[strlen(base) + strlen(insert)] = '\0';

	strcpy(base, temp);
	
	free(temp);
}

void reduce(char *base, size_t begin, size_t end)
{
	char *temp = calloc(strlen(base) - begin + end + 1, sizeof(char));
	
	strncpy(temp, base, begin);
	strcat(temp, base + end + 1);
	
	temp[strlen(base) - begin + end] = '\0';

	strcpy(base, temp);

	free(temp);
}

void add_backpack(backpack_t **backpack, size_t i, backpack_t *add_element)
{
	memcpy(backpack[i], add_element, sizeof(backpack_t));
}

void remove_backpack(backpack_t **backpack, size_t i)
{
	memset(backpack[i], 0, sizeof(backpack_t));
}

void print_arr(backpack_t **backpack, size_t size)
{
	for(int i = 0; i < size; i++)
	printf("{'%s', '%s', '%s', '%s', '%s', '%d'}\n",
	backpack[i]->brand_1.country, 
	backpack[i]->brand_1.name,
	backpack[i]->laptop_compartment,
	backpack[i]->color,
	backpack[i]->appointment,
	backpack[i]->volume);
}

void free_arr(backpack_t ***backpack, size_t size)
{	
	if (backpack == 0 || *backpack == 0)
		return;

	for (int i = 0; i < size; ++i)
		free(*(*backpack + i));

	free(*backpack);
}

char create_arr(backpack_t ***backpack, size_t size)
{
	if ((*backpack = (backpack_t **)
	calloc(size, sizeof(backpack_t *))) == 0)
		return 0;

	for (int i = 0; i < size; ++i) 
	{
		if ((*(*backpack + i) = (backpack_t *)malloc(
			     sizeof(backpack_t))) == 0) 
		{
			free_arr(backpack, i);
			return 0;
		}
	}
	return 1;
}
