#ifndef laba13
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define len_mass 11 
#define LENALP 26 
/**
 * @file lib.h
 * @brief Function deescriptoin file 
 * @version 1.0
 */
 /**
 * @mainpage 
 * **Завдання:** 
 *  **Реалізувати**   
 *  Задачі с розділу "на відмінно"
 *
 * @author Nosov Mykola.
 * @date 24-dec-2020
 * @version 1.0
 */
 
 /**
 * @brief Функція пошуку чисел у тексті 
 * @param char str[] - вхідний массив з текстом
 * @param int resmas[] - массив, у який записуємо результат 
 * @return count - кількість елементів
 */
int Digitftxt(char str[], int resmas[]);
 /**
 * @brief Функція виведення массиву 
 * @param int resmas[] - вхідний массив 
 * @param int count - кількість елементів массиву
 */
void printer(int resmas[], int count);
 /**
 * @brief Функція сортування за абеткою 
 * @param const void * a - 1 елемент
 * @param const void * b - 2 елемент, який порівнюється з 1
 * @return Результат порівняння 
 */
int toAlphabet (const void * a, const void * b);
 /**
 * @brief Функція частоти повторення елементів массиву
 * @param char mass[] - вхідний массив 
 */
void alpha_count(char mass[]);
 /**
 * @brief Функція знаходження кількості слів 
 * @param char string[] - вхідний массив 
 */
void stringf(char string[]);
#endif
