#include "lib.h"
/**
 * @file main.c
 * @brief Main functoin
 * @author 
 * @date 24-dec-2020
 * @version 1.0
 */
int main(void) {
    /*Task 1*/
    {
        char string[] = "cebra abra bebra"; /*Входной массив*/
        stringf(string);
    }
    printf("\n");
    /*Task 2*/
    {
        char text[] =
            "Иванов, Носов, Климко, Жук, Иванов, Жук, Носов, Сидоров"; /*Входной
                                                                          массив*/

        char newtext[sizeof(text) / sizeof(char) - 1];
        printf("text =  %s\n", text); /* Вывод входного массива*/

        char *find = strrchr(text, ',');
        while (1 == 1) {
            find = strrchr(text, ','); /*Обрабатываем запятые*/
            if (find != NULL) {
                if (strstr(newtext, find + 1) == NULL) {
                    strcat(newtext, find + 1);
                    strcat(newtext, ", ");
                    memset(find, '\0', sizeof(find));
                } else {
                    memset(find, '\0', sizeof(find));
                }
            } else {
                break;
            }
        }
        if (strstr(newtext, text) == NULL) {
            strcat(newtext, text);
        }
        printf("newtext =  %s\n", newtext);
    }
    /*Task 3*/
    {
        char mass[] = {"labu sdal?"}; /*Входной массив*/
        alpha_count(mass);
    }
    /*Task 4*/
    {
        char str[] = "sample text 452 with 324 numbers 2414"; /*Входной массив*/

        int *resmas =
            calloc(strlen(str),
                   sizeof(int)); /*Выделяем память для результирующего массива*/

        int chet = Digitftxt(str, resmas); /*Функция подсчета*/

        printer(resmas, chet); /*Функция вывода*/

        free(resmas);
    }
    return 0;
}
