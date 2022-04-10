#define pi 3.14
#include <stdio.h>

int main() {
	/* 1 Вычислить площадь, обьем, длинну окружности */
    float r = 3;
    char var = 'l';
    float result;
    switch (var) {
        case 's':
            result = pi * r * r;
            break;
        case 'l':
            result = 2 * pi * r;
            break;
        case 'v':
            result = (4 / 3) * pi * r * r * r;
            break;
    }

    /* 2 перевести дробную часть в целочисленное и поделить на значение до
     * запятой */

    float x2 = 123.456;
    int z2 = (int)x2;
    int c2 = (x2 - z2) * 1000;
    float d2 = (float)c2 / z2;
    d2 = d2 * 100;
    d2 = (int)d2;
    d2 = (float)d2 / 100;

    /* 3 Поменять значение переменных, что бы выполнялось равенство 8 */

    int k, m, n, o, p, q;
    k = 3;
    m = 2;
    n = 1;

    if (k == m || m == n || k == n) {
        char k[] = "Error: change variable value";
        char m[] = "Error: change variable value";
        char n[] = "Error: change variable value";

    } else {
        if (k > m) {
            o = k;
            k = m;
            m = o;
        }
        if (m > n) {
            p = n;
            n = m;
            m = p;
        }
        if (k > m) {
            o = k;
            k = m;
            m = o;
        }
    }
    /* 4 Вычислить y имея x */
    float x = 2;
    float y;
    if (x < -1)

    {
        y = -1 / x;

    } else if (x > -1 && x < 1) {
        y = x * x;
    } else {
        y = 1;
    }

    /* 5 Вычислить y имея x */
    float x1 = -2;
    float y1;
    if (x1 <= -1) {
        y1 = -1 * x1 - 1;
    } else if (x1 > -1 && x1 < 0) {
        y1 = x1 + 1;
    } else if (x1 > 0 && x1 < 1) {
        y1 = -1 * x1 + 1;

    } else if (x1 == 0) {
        y1 = 1;
    } else {
        y1 = x1 - 1;
    }

    return 0;
}
