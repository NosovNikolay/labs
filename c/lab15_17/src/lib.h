#ifndef M
#define M
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
/**
* Максимальный обьем рюкзака
*/
#define MAX_VOLUME_OF_BACKPACK 20
/**
* Количество рюкзаков
*/
#define BACKPACKS_COUNT 30
/**
* Структура содержащая информацию про бренд 
*/
struct brand
{
	char name[15];
	char country[15];
};
/**
* Структура содержащая информацию про рюкзак 
*/
struct backpack
{
	char laptop_compartment[4];
	char color[10];
	int volume;
	struct brand brand_1;
	char appointment[10];
};
/**
 * Функция считывает информацию в текстовом виде из файла 
 * 
 * @param *filename Имя файла
 * 
 * @return 0 в случае успеха
 */
int read_text(char * filename);
/**
 * Функция записывает информацию в текстовом виде в файл
 * 
 * @param backpack *back  Массив структур 
 * 
 * @return 0 в случае успеха
 */
int write_text(struct backpack *p);
/**
 * Функция заполняет массив структур на основе псевдослучайных чисел
 * 
 * @param backpack *back  Массив структур 
 * @param count Количество структур в массиве
 * 
 * @return 0 в случае успеха
 */
unsigned char fill_massive(struct backpack *back, unsigned char count);
/**
 * Функция записывает переданный массив структур в файл в бинарном виде
 * 
 * @param backpack *back  Массив структур 
 * @param count Количество структур в массиве
 * 
 * @return 1 в случае успеха, 0 в случае ошибки
 */
unsigned char write_bin(struct backpack *back, unsigned char count);
/**
 * Функция считывает информацию в бинарном виде из файла и записывает в массив
 * 
 * @param backpack *back  Массив структур 
 * @param count Количество структур в массиве
 * 
 * @return 1 в случае успеха, 0 в случае ошибки
 */
unsigned char read_bin(struct backpack *back, unsigned char count);
/**
 * Функция находит нужный элемент массива за заданым критерием
 * 
 * @param backpack *back  Массив структур 
 * @param input Критерий
 * 
 */
void search(char input[], struct backpack *back);
/**
 * Функция выводит на экран содержимое структуры 
 * 
 * @param backpack - структура 
 * 
 */
void print(struct backpack back);
/**
 * Функция находит нужный элемент массива за заданым критерием
 * 
 * @param backpack *back  Массив структур 
 * @param input Критерий
 * 
 */
void search_1(char input[], struct backpack *back);
/**
 * Функция сортирует элементы массива по возрастанию обьема рюкзака 
 * 
 * @param backpack *back  Массив структур 
 * 
 */
void sort_by_volume(struct backpack *back);
#endif 
