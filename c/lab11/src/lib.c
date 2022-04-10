#include "lib.h"
int nep_posl(int mass[], int size, int count)
{
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < 0)
		{
			count++;
			i++;	
		}
	}
	if (mass[0] > 0)
	{
		count++;
	}
	if (mass[size - 1] > 0)
	{
		count++;
	}
	return count;
}
void schet(int block[], int mass[], int *chetmas)
{
	for (int i = 0, j, q = 0, chet; i < LEN * 2; q+=2)
	{
		chet = 1;
		for (j = i + 1; j < LEN * 2; j++)
		{
			if (mass[j] == mass[i])
			{
				chet++;
			}
			else 
			{
				break;
			}
		}
		block[q] = mass[i];
		block[q + 1] = chet;
		i = j;
	}
	for (int i = 0; i < *chetmas * 2; i+= 2)
	{
		printf ("%d - ", block[i]);
		printf ("%d ", block[i + 1]);
		printf ("\n");
	}
}
void randomize(int mass[])
{
	for (int i = 0; i < LEN; i++)
	{
		mass[i] = rand() % 10;
		printf("%d ", mass[i]);
	}	
}
void bubbleSort(int *num, int size) /* Пузырьковая сортировка*/ 
{
  	for (int i = 0; i < size - 1; i++)
  	{
    		for (int j = (size - 1); j > i; j--) 
    		{
      			if (num[j] < num[j - 1]) 
      			{
        			int temp = num[j - 1]; /* меняем их местами*/
        			num[j - 1] = num[j];
        			num[j] = temp;
      			}
    		}
  	}
}
void diagonal(int mass2[LEN][LEN])
{
	for (int i = 0; i < LEN; i++)
	{
		for(int j = 0; j < LEN; j++)
		{
			mass2[i][j] = rand()%10;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		for(int j = 0; j < LEN; j++)
		{
			printf("%d ", mass2[i][j]);
		}	
		printf("\n");
	}
	int resmass[LEN];
	for (int i = 0; i < LEN; i++)
	{
		resmass[i] = mass2[i][i];
	}
	printf("\n");
	bubbleSort(resmass, LEN);
	for (int i = 0; i < LEN; i++)
	{
		printf("%d ", resmass[i]);
	}
	printf("\n\n");
}
void schet1(int mass[], int size)
{
	/*Цикл, который находит количество непрерывных последовательностей */
	int count;
	nep_posl(mass, size, count);
	/* Создание двухмерного массива */
	const int ccount = count - 1;
	const int csize = size + 1;
	int resmas[ccount][csize];
	/* Заполнение двухмерного масиива нулями */
	for (int i = 0; i < ccount; i++ )
	{
		for (int j = 0; j < csize; j++)
		{
			resmas[i][j] = 0;
		}
	}
	/* Заполнение двухмерного массива нужными значениями */
	int j = 0;
	for (int i = 0; i < ccount; i++)
	{
		for (int q = 0;j < csize - 1 ;j++, q++)
		{
			if (mass[j] > 0)
			{
				resmas[i][q] = mass[j];
			}
			else
			{
				j++;
				break;
			}
		}
	}
/* Вычисление суммы */
	int sum = 0;
	for (int i = 0; i < ccount; i++ )
	{
		for (int j = 0; j < csize - 1; j ++)
		{
			sum = sum + resmas[i][j];
		}
		resmas[i][csize - 1] = sum;
		sum = 0;
	}
/* Определение большей части */
	int ch = 0;
	for (int i = 0; i < ccount; i++)
	{
		if (resmas[ch][csize - 1] < resmas[i][csize - 1])
		{
			ch = i;
		}
	}
/* Создание результирующего масиива */
	int chet = 0;
	for (int i = 0; i < csize - 1; i ++)
	{
		if (resmas[ch][i] != 0)
		{
			chet += 1;
		}
	}
	int * block = calloc(chet , sizeof(int)); 
	
	for (int i = 0; i < chet; i++)
	{
		block[i] = resmas[ch][i];
		printf("%d ", block[i]);
	}
	printf("\n");
	free(block);
	}
void posled(double mass[], int size)
{
	int count = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (mass[i + 1] < mass[i])
		{
			count++;
		}
	}
	/* Создание 2х мерного массива */
	const int constcount = count;
	const int constsize = size + 1;
	
	double resmas[constcount][constsize];
	
	/*Заполнение двухмерного массива нулями */
	
	for (int i = 0; i < constcount; i++ )
	{
		for (int j = 0; j < constsize; j++)
		{
			resmas[i][j] = 0;
		}
	}
	/*Заполнение двухмерного массива нужными значениями */
	int j = 0;
	for (int i = 0; i < constcount; i++)
	{
		for ( int q = 0 ; j < constsize - 1; j++)
		{
			if (mass[j + 1] < mass[j])
			{
				resmas[i][q] = mass[j];
				q++;
				j++;
				break;
			}
			else
			{
				resmas[i][q] = mass[j];
				q++;
			}
		}
	}
	/* Подсчет количества символов */
	for (int j = 0; j < constcount; j++)
	{
		for (int i = size, chet = constsize; i < constsize; i--)
		{
			if(resmas[j][i] == 0)
			{
				chet--;
			}
			else
			{
				resmas[j][constsize - 1] = chet;
				break;
			}
		}
	} 
	/* Определение большей части */
	int biggest = 0; 
	for (int i = 0; i < constcount; i++)
	{
		if (resmas[biggest][constsize - 1] < resmas[i + 1][constsize - 1])
		{
			biggest = i + 1;
		}
	}
	/* Создание результирующего массива */
	float * block = calloc( (int)resmas[biggest][constsize - 1] , sizeof(float)); 
	for (int i = 0; i < resmas[biggest][constsize - 1]; i++)
	{
		block[i] = resmas[biggest][i];
		printf("%f ", block[i]);
	}
	printf("\n");
	free(block);
	}
