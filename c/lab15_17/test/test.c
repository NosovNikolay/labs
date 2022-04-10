#include"lib.h"
unsigned char test_write_read_bin()
{
	printf("Running test \"%s\"...\n", __FUNCTION__);
	
	struct backpack *backpacks = calloc(BACKPACKS_COUNT, sizeof(struct backpack));
	struct backpack *backpacks_res = calloc(BACKPACKS_COUNT, sizeof(struct backpack));

	fill_massive(backpacks, BACKPACKS_COUNT);

	if (!write_bin(backpacks, BACKPACKS_COUNT) ||
	    !read_bin(backpacks_res, BACKPACKS_COUNT)) 
	{
		printf("Can't allocate memory\n");
		free(backpacks);
		free(backpacks_res);
		return 0;
	}

	for (int i = 0; i < BACKPACKS_COUNT; ++i)
	{
		if(backpacks[i].volume != backpacks_res[i].volume
		&& strcmp(backpacks[i].color, backpacks_res[i].color) 
		&& strcmp(backpacks[i].laptop_compartment, backpacks_res[i].laptop_compartment)
		&& strcmp(backpacks[i].appointment, backpacks_res[i].appointment)
		&& strcmp(backpacks[i].brand_1.name, backpacks_res[i].brand_1.name)
		&& strcmp(backpacks[i].brand_1.country, backpacks_res[i].brand_1.country))
		{
			printf("Error in func %s", __FUNCTION__);
			free(backpacks);
			free(backpacks_res);
			return 0;
		}
	}
	free(backpacks);
	free(backpacks_res);
	return 1;
}
unsigned char test_by_sort()
{	
	printf("Running test \"%s\"...\n", __FUNCTION__);
	
	struct backpack *backpacks = calloc(BACKPACKS_COUNT, sizeof(struct backpack));	
	fill_massive(backpacks, BACKPACKS_COUNT);
	sort_by_volume(backpacks);
	for(int i = 0; i < BACKPACKS_COUNT - 1; i++)
	{
		if(backpacks[i].volume > backpacks[i + 1].volume)
		{
			free(backpacks);
			printf("Error in func %s", __FUNCTION__);
			return 0;
		}
	}
	free(backpacks);
	return 1;
}
unsigned char max_value()
{
	printf("Running test \"%s\"...\n", __FUNCTION__);
	
	struct backpack *backpacks = calloc(BACKPACKS_COUNT, sizeof(struct backpack));	
	fill_massive(backpacks, BACKPACKS_COUNT);
	for(int i = 0; i < BACKPACKS_COUNT - 1; i++)
	{
		if(backpacks[i].volume > MAX_VOLUME_OF_BACKPACK)
		{
			free(backpacks);
			printf("Error in func %s", __FUNCTION__);
			return 0;
		}
	}
	free(backpacks);
	return 1;
}
int main(void)
{
	unsigned char result = 1;
	
	result &= test_write_read_bin();
	result &= test_by_sort();
	result &= max_value();
	
	if(result)
		printf("Test is passed! Programm is ready!\n");	
	else
		printf("Test is not passed. Try to find bugs in your programm.\n");
}
