/**
 * @file lib.h
 *  @brief Файл с прототипами функций для решения заданий из лабораторной работы №14

 * @author
 * @version 1.0
 * @date 
 */

#ifndef LIB_H
#define LIB_H

#define RAND_MAX_NUMBER 10

#define RAND_OFFSET (-5)


#define T2_DELIM "	 \n"

#define T2_FILENAME_SIZE 256

/** Признак директории */
#define ID_DIR 4

/** 
 * Функция считает кол-во найденых слов в строке
 *
 * @param input строка для поиска слов
 * @return количество найденных слов
 */
unsigned int getwc(char *input);

/** 
 * Функция читает строку определённой длинны из файла (Добавляет нуль-терминатор в конец строки)
 *
 * @param filename имя файла
 * @param buf Строка, в которую будет записываться текст
 * @param buf_size Размер строки (Включая нуль-терминатор)
 * @return 1 при успешном чтении, 0 при невозможности открыть файл
 */
char readfromfile(char *filename, char *buf, unsigned int buf_size);

/** 
 * Функция записывает строку в файл
 *
 * @param filename имя файла
 * @param buf Строка, из которой будет переписываться текст
 */
void writetofile(char *filename, char *data);

/** 
 * Функция рекурсивно выводит структуру каталогов в консоль
 *
 * @param catalog имя каталога
 * @param offset Отступ перед каталогом
 */
void tree(char *catalog, unsigned int offset);

/** 
 * Функция рекурсивно подсчитывает размер каталога
 *
 * @param catalog имя каталога
 * @return размер каталога в байтах
 */
long getcatsize(char *catalog);

/** 
 * Функция заполняет матрицу случайными числами
 *
 * @param input Матрица
 * @param size Размер матрицы
 */
void fillrnd(int *input, unsigned int size);

/** 
 * Функция переписывает в переданный массив диагональ матрицы
 *
 * @param input Матрица
 * @param size Размер матрицы
 * @param diag Массив, в который будут переписаны элементы диагонали матрицы
 */
void getdiag(int *input, unsigned int size, int *diag);

#endif /* LIB_H */

