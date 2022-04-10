#include"lib.h" 
int main(void)
{
	/*Базовий клас, запис у файл*/
	char * filename = "base.txt";
	struct backpack base = {{"yes"}, "black", 23, {{"adibas"}, {"Tajikistan"}}, {"tactical"}};

	/*Запис та читання у текстовому вигляді базової структури*/
	write_text(&base);
	read_text(filename);
   
	/*Для виводу базової структури*/
	printf("\n-----------------------------\n\n");
	printf("Example of our products :\n");
	print(base);
    
    /*Псевдовипадкове створення структур*/
	struct backpack *backpacks = calloc(BACKPACKS_COUNT, sizeof(struct backpack));
    
	srand(time(0));
    
	fill_massive(backpacks, BACKPACKS_COUNT);
    
	/*Сортування за обʼємом*/
	sort_by_volume(backpacks);
    
	/*Запис та читання у бінарному вигяді массиву стуктур*/
	if(!write_bin(backpacks, BACKPACKS_COUNT)) 
	{	
    	/*Якщо не виконався запис*/
		free(backpacks);
		return 1;
	}
	if (!read_bin(backpacks, BACKPACKS_COUNT)) 
	{	
		/*Якщо не виконалось читання*/
		free(backpacks);
		return 1;
	}
	printf("Please, choose the color of backpack you want to see (yellow, black, blown, green):\n");
	char input[100] = {};
	gets(input);
	
	/*Пошук потрібної структури*/
	search(input, backpacks);
	
	free(backpacks);
	return 0;
}




