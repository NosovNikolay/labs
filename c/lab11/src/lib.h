#ifndef Mudol
#define Mudol
#define LEN 5
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
 
 /**
 * @brief 
 * @param int block - результуючий массив
 * @param int mass - массив із всіма числами
 * @param int *chetmas - впорядкованний массив
 */
void schet(int block[], int mass[], int *chetmas);
 /**
 * @brief 
 * @brief заповнення випадковими числами
 * @param массив
 */
void randomize(int mass[]);
 /**
 * @brief сортування
 * @param массив, кількість елементвів массиву
 */
void bubbleSort(int *num, int size);
 /**
 * @brief основний цилк задачі 4
 * @param int mass2 - массив
 */
void diagonal(int mass2[LEN][LEN]);
 /**
 * @brief основний алгоритм 2 задачі 
 * @param int mass[] - основний массив 
 * @param int size - кількість елементів 
 */
void schet1(int mass[], int size);
 /**
 * @brief основний алгоритм задачі 3 
 * @param double mass[] - вхідний массив 
 * @param int size - кількість елементів массиву
 *
 */
void posled(double mass[], int size);
 /**
 * @brief Підрахунок кількості послідовностей 
 * @param int mass[] - вхідний массив
 * @param int size - кількість елементів
 * @param int count - змінна для кількості послідовностей 
 */
int nep_posl(int mass[], int size, int count);

#endif
