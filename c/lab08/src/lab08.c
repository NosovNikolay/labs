/**
 * @brief CONSTANT
 *
 */
#define N 10
/**
 * @brief Кількість елементів масива
 *
 */
#define LEN 15
/**
 * Файл з кодом програми
 */
/**
 * @brief Бібліотека для варіативої функції та стандартна бібліотека
 *
 */
#include <stdarg.h>
#include <stdio.h>

/**
 * @file lab07.c
 * @brief Файл з функціями
 *
 * @author -
 * @date 27-nov-2020
 * @version 1.0
 */

/**
 * @mainpage
 * # Загальне завдання :
 *
 * **Завдання:**
 *  Переробити завдання з 5 та 6 лабораторної роботи у функції, згідно з
 * лабораторним практикумом
 *
 *
 * @author -
 * @date 27-nov-2020
 * @version 1.0
 */

/**
 *
 * @brief Функія обчислює найбільший спільний дільник
 * @param 2 числа
 * @return НОД
 */
int nod1(int a, int b) {
    int nod;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        printf("Невозможно найти НОД\n");
        return 0;
    }
    if (a == 0 || b == 0) {
        printf("Невозможно найти НОД\n");
        return 0;
    } else {
        while (a != 0 && b != 0) {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        nod = a + b;
    }
    return nod;
}
/**
 * @brief Функція визначає, чи є білетик щасливим
 * @param Білетик
 * @return Так або ні
 */
int lucky_ticket(int n) {
    int x2 = 0;
    int x3 = 0;
    int j = 0;
    if (n < 0 || n == 0) {
        printf("Невозможно определить, счастливы ли билетик\n");

    } else {
        do {
            j++;
            x2 += n % 10;
            n /= 10;
        } while (j < 3);
        j = 0;
        do {
            j++;
            x3 += n % 10;
            n /= 10;
        } while (j < 3);
        if (x2 == x3) {
            j = 1;
        } else {
            j = 0;
        }
    }
    return j;
}
/**
 * @brief Фунція визначає чи є число простим
 * @param Число
 * @return Так або ні
 */
int prime_digit(int a12) {
    int result;
    if (a12 < 0 || a12 == 0) {
        printf("Невозможно определить, простое ли число\n");
    } else {
        for (int i = 2; i < a12;
             i++) { /*Тут должен быть sqrt, но нам запретили :( */
            if (a12 % i == 0) {
                result = 0;
                break;
            } else
                result = 1;
        }
    }
    return result;
}
/**
 * @brief Функція визначає, чи є число ідеальним
 * @param Число
 * @return Так або ні
 */
int ideal_digit(int bi) {
    int pi = 1;
    int ci = 0;
    if (bi < 0 || bi == 0) {
        printf("Невозможно определить, иделаьно ели число\n");
    } else {
        for (pi; pi < bi; pi++)
            if (bi % pi == 0) ci = ci + pi;
        if (ci == bi)
            pi = 1;
        else
            pi = 0;
    }
    return pi;
}
/**
 * @brief Функція обчислює квадртаний корінь чилса
 * @param Число
 * @return Квадратний корінь заданого числа
 */
float sqrt1(float num) {
    /* Проверка числа на корректность */
         float digit = num;
        /* Проверка числа на корректность */
        if (digit < 0.f) return 1;

        float sqrt = digit / 2.f;
        float x;

        /* Поиск корня методом Ньютона (методом касательных) */
        do {
            x = sqrt;
            sqrt = (x + (digit / x)) / 2.f;
        } while (x - sqrt > 0.f);
		return x;
}
/**
 * @brief Функція визначає кількість пар, де перше число меньше наступного
 * @param Числова послідовність
 * @return Кількість пар
 */
int couples(int var, ...) {
    int count = 0;
    va_list vl;
    va_start(vl, var);
    int mass[var];

    for (int i = 0; i < var; i++) {
        mass[i] = va_arg(vl, int);
        printf("%d\n", mass[i]);
    }

    for (int i = 0; i < var - 1; i++) {
        if (mass[i] < mass[i + 1]) {
            count++;
        }
    }
    va_end(vl);
    return count;
}

/**
 * @brief Фукнція центрує слово або словосполучення у рядку
 * @param Массив із словом або словосполученням
 */
void centrovka(char mass[]) {
    int centr = 0;
    int shetBukv = 0;
    int firstChar;

    for (int i = 0; i < LEN; i++) {
        if (mass[i] != ' ') {
            firstChar = i; /* обработка пробелов */
            break;
        }
    }
    for (int i = 0; i < (LEN - 1); i++) {
        if (mass[i] != '\0' && mass[i] != ' ') {
            shetBukv++;
        }
        if (mass[i] == ' ' && mass[i + 1] != ' ' &&
            mass[i - 1] != ' ') /* обработка пробела между словами */
        {
            shetBukv++;
        }
    }
    centr = ((LEN - shetBukv) / 2);
    char newmass[LEN] = {};
    for (int i = 0; i < (LEN - 1); i++) {
        newmass[i] = '_'; /*Заполнитель */
    }
    for (int i = 0; i < shetBukv; i++) {
        newmass[centr + i] = mass[i + firstChar];
    }
    for (int i = 0; i < LEN - 1; i++) {
        mass[i] = newmass[i]; /* Перезаписываем в изначальный массив */
    }
}
/**
 * @brief Головна фунція, що викликає всі інші функціі
 * @param відсутні
 * @return Помилка або її відсутність
 *
 */
int main() {
    char mass[LEN] = "   Ivan Borov  "; /* Слово,которое нужно отцентровать */
    centrovka(mass);
    printf("%s", mass);
    couples(3, 1, 2, 3);
    int nod = nod1(520, 260);
    printf("%d\n", nod);
    int j = lucky_ticket(123123);
    printf("%d\n", j); /* 1 - счастливый, 0 - не счатстливый */
    int result = prime_digit(7);
    printf("%d\n", result); /*1 - простое , 0 - не простое */
    int pi = ideal_digit(7);
    printf("%d\n", pi); /* 1 - идеально, 0 - не идеальное */
    float sqrt = sqrt1(200);
    return 0;
}
