#include "lib.h"
/**@file main.c
 *@brief Головний файл программи
 */
/**
 * @mainpage
 * 
 */
/**
 * @brief Головна функція программи, яка викликає всі інші функції
 */
int main() {
    srand(time(NULL));

    /*Task 4 */
    {
        int mass[LEN][LEN] = {};
        diagonal(mass);
    }
    /*Task1*/
    {
        int mass[LEN];
        randomize(mass);
        printf("\n");
        bubbleSort(mass, LEN);

        /*Считаем сколько памяти надо новому массиву*/
        int chetmas = 0;
        chetmas = count(mass, chetmas);
        /* Выделение памяти для результирующего массива*/
        int b = 20;
        int* block = calloc(b, sizeof(int));
        /*Основной цикл программы*/

        schet(block, mass, &chetmas);

        free(block);
    }
    /*Task 2*/
    /* Входной массив */
    {
        int mass[] = {1,  2, -4, 2,  4,   -2, -4, 2,   4,   6,
                      -6, 7, 8,  23, -56, 54, 23, -11, -45, 45};
        int size = sizeof(mass) / sizeof(mass[0]);

        schet1(mass, size);
    }
    {
        /*Task3*/
        /*Входной массив*/
        double mass[] = {1.5, 2.5, 3.25, 4.1, 1.2, 2.05, 3.4, 4.18, 5.23, 6.80};
        int size = sizeof(mass) / sizeof(double);
        posled(mass, size);
        return 0;
    }
}
