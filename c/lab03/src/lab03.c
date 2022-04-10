#include <stdio.h>


int main() {
	/*1 Сопротивление резисторов*/
	float r, r1 = 1,  r2 = 2, r3 = 3;
	r = 1 / ((1 / r1) + (1 / r2) + (1 / r3));

    /*2 Перевернуть число*/
	int n = 225, num1, num2, num3, reverse;

	num1 = n / 100;
    num2 = (n % 100) / 10;
    num3 = n % 10 ;

    reverse = 100 * num3 + 10 * num2 + num1;
	
	/*3 Возвести в степень за 2,3,4 действия */
    int a, a4, a6, a8, a10;
    a = 2;
    a4 = a * a;
    a4 = a4 * a4;
    a6 = a * a * a;
    a6 = a6 * a6;
    a8 = a * a;
    a8 = a8 * a8;
    a8 = a8 * a8;
    a10 = a4 * a;
    a10 = a10 * a10;

    /*4 Перевести в 10-ую систему исчислений*/
    int chislo, p, a3, b4, c4, d4, chislo10;
    chislo = 1337;
    p = 8;
    a3 = (chislo / 1000) * (p * p * p);
    b4 = ((chislo / 100) % 10) * (p * p);
    c4 = ((chislo / 10) % 10) * p;
    d4 = chislo % 10;
    chislo10 = a3 + b4 + c4 + d4;

    /*5 Поделить первую цифру числа на последнюю*/
    int x = 123;
    int b1 = x / 100;
    int c1 = x % 10;
    int a5 = (int)((float)b1 / (float)c1 * 100);
    float result = (float)a5 / 100;

    /*6 Сумма арифметической прогрессии*/
    float a1, an, c6, suma;
    a1 = 10;
    an = 15;
    c6 = (an - a1) + 1;
    suma = ((a1 + an) / 2) * c6;

	(void)r;
	(void)chislo10;
	(void)suma;
	(void)result;
	(void)reverse;

    return 0;
}
