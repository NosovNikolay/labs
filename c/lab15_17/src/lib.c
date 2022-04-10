#include"lib.h"
int write_text(struct backpack *p)
{
	FILE * fp;
	char *c;
    
	/*Кількість байтів*/
	int size = sizeof(struct backpack); 
	if ((fp = fopen("dist/massive_text.dat", "w")) == 0) 
	{
		perror("Error occured while opening file");
		return 1;
	}
	c = (char *)p;
	for (int i = 0; i < size; i++)
	{
		putc(*c++, fp);
	}
	fclose(fp);
	return 0;
}

int read_text(char * filename)
{
	FILE * fp;
	char *c;
	int i; 
    
	int size = sizeof(struct backpack);
	struct backpack * ptr = (struct backpack *) malloc(size);
 
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror("Error occured while opening file");
		free(ptr);
		return 1;
	}
	c = (char *)ptr;
	while ((i = getc(fp))!=EOF)
	{
		*c = i;
		c++;
	}
	fclose(fp); 
	free(ptr);
	return 0;
}

unsigned char fill_massive(struct backpack *back, unsigned char count)
{
	char *color[] = {"black","yellow","green","blown"};
	char *brand[] = {"nike", "adidas", "superdry", "epam"};
	char *country_of_brand[] = {"Russia", "Taiwan", "China"};
	char *appointment[] = {"tactical", "urban", "sports"};
	char *laptop_compartment[] = {"yes", "no"}; 
	unsigned char i = 0; 
	for (i = 0; i < count; ++i) 
	{
		strcpy(back->brand_1.country, country_of_brand[rand()%3]);
		strcpy(back->brand_1.name, brand[rand()%4]);
		strcpy(back->laptop_compartment, laptop_compartment[rand()%2]);
		strcpy(back->appointment, appointment[rand()%3]);
		strcpy(back->color, color[rand()%4]);
		back->volume = (unsigned char)
		(rand() % MAX_VOLUME_OF_BACKPACK);
		++back;
	}
	return 1;
}

void search(char input[], struct backpack *back)
{
	int n = 0;
	for (int i = 0; i < BACKPACKS_COUNT; i++)
	{
		if (strcmp(back[i].color, input))
		{
			n++;
		}
		if(n == BACKPACKS_COUNT - 1)
		{
			printf("Sorry, we don't have %s bakcpacks\n", input);
			exit(0);
		}
	}
	for (int i = 0; i < BACKPACKS_COUNT; i++)
	{
		if(strcmp(back[i].color, input) == 0)
		{
			print(back[i]);
		}
	}
	printf("Please, choose the brand of backpack :\n");
	search_1(input, back);
}

void print(struct backpack back)
{
	printf("Appointment: %s\n", back.appointment);
	printf("Laptop compartment: %s\n", back.laptop_compartment);
	printf("Color: %s\n", back.color);
	printf("Brand: %s\n", back.brand_1.name);
	printf("Volume in liters: %d\n", back.volume);
	printf("Country of brand: %s\n", back.brand_1.country);
	printf("\n-----------------------------\n\n");
}

void search_1(char input[], struct backpack *back)
{
	char input_1[10];
	gets(input_1);
	for (int i = 0; i < BACKPACKS_COUNT; i++)
	{
		if(strcmp(back[i].color, input) == 0 &&
		strcmp(back[i].brand_1.name, input_1) == 0)
		{
			print(back[i]);
		}
	}
}

unsigned char write_bin(struct backpack *back, unsigned char count)
{
	FILE *file; 

	if ((file = fopen("dist/massive_bin.dat", "wb")) == 0) 
	{
		printf("Error in %s, can't open file\n", __FUNCTION__);
		return 0;
	}
	/* Записать массив в бинарном виде */
	fwrite(back, sizeof(struct backpack), count, file);

	fclose(file);
	return 1;
}

unsigned char read_bin(struct backpack *back, unsigned char count)
{
	FILE *file; 

	if ((file = fopen("dist/massive_bin.dat", "rb")) == 0) 
	{
		printf("Error in %s, can't open file\n", __FUNCTION__);
		return 0;
	}
	fread(back, sizeof(struct backpack), count, file);

	fclose(file);
	return 1;
}

void sort_by_volume(struct backpack *back)
{
	for(int i = 0; i < BACKPACKS_COUNT - 1; i++)
	{
		for(int j = 0; j < BACKPACKS_COUNT - 1; j++)
		{
			if(back[j].volume > back[j+1].volume)
			{
				int res_volume = back[j].volume;
				back[j].volume = back[j + 1].volume;
				back[j + 1].volume = res_volume;
			}
		}
	}
}
