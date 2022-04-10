#include "lib.h"
/**
 * @file lib.c
 * @brief Function impelementation file 
 * @version 1.0
 */
void alpha_count(char mass[])
{
	char alphabet[LENALP] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u','v', 'w', 'x', 'y', 'z' };
	int quatity[LENALP] = {};
	int count = 0;
	for (int i = 0; i < LENALP; i++) 
	{
		count = 0;
	    for ( int j = 0; j < len_mass; j++)
	    {
	      	if (alphabet[i] == mass[j]) 
	      	{
	        	count++;
	      	}
	    }
	    quatity[i] = count;  
	}

	printf("\n");
  	int sum = 0;
  	for (int i = 0; i < LENALP; i++)
  	{
    	sum = sum + quatity[i];
  	}
  	float frequency[LENALP] = {};
  	printf("%s\n", mass);
  	for (int i = 0; i < LENALP; i++) 
  	{
    	frequency[i] = (float)quatity[i] / sum;
   		if(frequency[i] != 0)
   		{
    		printf("%f ", frequency[i]); 
    		printf("%c\n", alphabet[i]);
		}
  	}
}
void stringf(char string[])
{
	char sep[10]=" ";
    /* Переменная, в которую будут заноситься начальные адреса частей*/
    /* строки str*/
    char *istr;

    /* Выделение первой части строки*/
    istr = strtok (string,sep);

    int k = 0;

    char * s[200];

    //выделение последующих частей и занесение из изначального массива в массив s
    while (istr != NULL)
    {
        s[k] = istr;
        istr = strtok(NULL,sep); 
        k++;
    }

    printf("%d\n", k);

    int i = 0; 
 
    /*сортировка по возрастанию*/
    qsort (s, k, sizeof(char**), toAlphabet);
    
    /*вывод результатов на экран*/
    for(i=0; i < 3; i++)
    {
		if (s[i] != '\0')
		{
        	printf("%s ", s[i]);
		}
    }
}
int Digitftxt(char str[], int resmas[])
{
	int x;
	int count = 0;
	for(int i = 0;i < strlen(str);i++)
    {
        if(str[i] != ' ')
        {
            if((str[i] >= '1') && (str[i] <= '9') && (str[i] != ' '))
            {
                x = ((int)str[i] - 48);
                resmas[count] = x;
                count++;
                if( (str[i + 1] < '1') || (str[i + 1] > '9') )
                {
                	resmas[count] = 91292149;
                	count++;
                }
            }
        }
    }
  	return count;
}
void printer(int resmas[], int count)
{
	for (int i = 0; i < count; i++)
    {
    	if (resmas[i] == 91292149)
    	{
			printf("\n");
    	}
    	else
    	{
    	    printf("%d", resmas[i]);
    	}
    }

}
int toAlphabet (const void * a, const void * b)
{
  	return strcmp(*(char**)a,*(char**)b); /*Это что то страшное*/
}
