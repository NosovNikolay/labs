#define DIGIT_T1_1 80 /**< Число для задания 1 */
#define DIGIT_T1_2 56 /**< Число для задания 1 */

#define DIGIT_T2 4 /**< Число для задания 2 */

#define DIGIT_T3 102300 /**< Число для задания 3 */

#define DIGIT_T4 28 /**< Число для задания 4 */

#define DIGIT_T5 49.f /**< Число, корень из которого нужно извлечь */

#include <stdio.h>
int main() {
    /*1 Найти найбольший общий делитель 2-х чисел*/
    /* --- Задание 1 --- */
    {
        int d1 = (DIGIT_T1_1 > DIGIT_T1_2) ? DIGIT_T1_1
                                           : DIGIT_T1_2; /* Большее число */
        int d2 = (DIGIT_T1_1 < DIGIT_T1_2) ? DIGIT_T1_1
                                           : DIGIT_T1_2; /* Меньшее число */
        int result;
        int temp;

        while (d2 > 0) {
            temp = d1;
            d1 = d2;
            d2 = temp - (temp / d2) * d2;
        }

        result = d1;
		(void)result;
    }

    /* --- Задание 2 --- */
    {
        int i = (DIGIT_T2 > 0) ? DIGIT_T2 : -DIGIT_T2;
        unsigned int divider_count = 0;
        char result;

        for (; i > 0 && divider_count <= 2; --i)
            if (DIGIT_T2 % i == 0) ++divider_count;

        /* Число является простым, если оно имеет лишь 2 делителя */
        result = (divider_count == 2) ? 1 : 0;
		(void)result;
    }

    /* --- Задание 3 --- */
    {
        int digit = DIGIT_T3;

        int sum_first = 0, sum_second = 0;
        /* Итератор */
        int i;
        int result;

        for (i = 0; i < 3; ++i) {
            sum_first += digit % 10;
            digit /= 10;
        }

        for (i = 0; i < 3; ++i) {
            sum_second += digit % 10;
            digit /= 10;
        }

        result = (sum_first == sum_second) ? 1 : 0;
		printf("%d\n", result);
		(void)result;
    }

    /* --- Задание 4 --- */
    {
        int digit = DIGIT_T4;
        int sum = 1; 
        int i;       
        char result; 

        /* 2 - минимальное значащее число */
        for (i = 2; i < digit; ++i)
            if (digit % i == 0) sum += i; /* Прибавляем делитель к сумме */

        result = (sum == digit) ? 1 : 0;
		(void)result;
    }

    /* --- Задание 5 --- */
    {
        /* Данное число */
        float digit = DIGIT_T5;
        /* Проверка числа на корректность */
        if (digit < 0.f) return 1;

        float sqrt = digit / 2.f;
        float x;

        /* Поиск корня методом Ньютона (методом касательных) */
        do {
            x = sqrt;
            sqrt = (x + (digit / x)) / 2.f;
        } while (x - sqrt > 0.f);
		(void)x; 
    }
	

    return 0;
}
