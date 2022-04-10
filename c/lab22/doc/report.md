# Лабораторна робота №22.Регулярні вирази 

 **Навчитися обробляти текст використовуючи регулярні вирази** 

## 1 Вимоги

### 1.1 Розробник

- Носов Микола Володимирович;
- студент групи КІТ-120Б;
- 6-05-2020.

### 1.2 Загальне завдання
Розширити попередню лабораторну роботу таким чином, щоб:

1. При введенні інформації про базовий тип була проведена перевірка її відповідності таким критеріям (з допомогою регулярних виразів):
- Можна вводити лише кириличні й латинські символи, цифри, пропуски і розділовий знаки
- Не повинно бути пропусків і розділових знаків, які повторюються
- Перше слово не повинно починатися з маленького символу
2. В клас-список додати метод, який виводить на екран список всіх об'єктів, які мають одне або більше поля з як мінімум двома словами (перевірку здійснити за допомогою регулярних виразів)  

### 1.3 Індивідуальне завдання
1. Виконати завдання 

## 2 Опис програми 

### 2.1 Функціональне призначення

Программа призначена для:

 - демонстрації виконання прикладних задач лабораторної роботи №19-20, доповнених перевіркою за допомогою регулярних виразів 
 
### 2.2 Логічна структура проекту 

#### Логічна структура проету :

 - Структура проекту
  
``` 
.
├── doc
│   ├── assets
│   │   ├── work(1).png
│   │   ├── work(2).png
│   │   ├── main_func.png
│   │   ├── valgrind.png
│   │   ├── cppcheck.png
│   │   └── define.png
│   └──readme.md
├── test
│   └── test.c
├── Doxyfile
├── Makefile
├── README.md
├── .gitignore
└── src
    ├── list.c
    ├── list.h
    ├── data.c
    ├── data.h
    └── main.c
```
 
**Основна функція:**
> int main(void);

Призначення :
 - вирішує поставлені задачі
 - повертає 0 у разі успішного завершення програми

**Функції програми**
```c
dllist_t *create_dllist();
```

Призначення: Створює двузвʼязний список 

Опис роботи:
 - Виділення пам'яті
 - Встановлення вказівників початку та кінця списку на NULL
 - Встановлення довжини списку на 0
 - Повернення вказіника на стуктуру списку 
---

```c
void free_dllist(dllist_t **list);
```

Призначення: Звільнення займаємої пам'яті списком 

Опис роботи:
 - Встановлення вказівника на кінець списка
 - Циклічне звільнення елементів з кінця до початку
 - Звільнення першого елемента
 - Звільнення пам'яті відведену під структуру списка 

Аргументи:
 - dllist_t **list - вказівник на вказівних на структуру списка
---

```c
element_t *find_in_dllist(dllist_t *list, size_t pos);
```

Призначення: Пошук елемента за індексом

Опис роботи:
 - Встановлення вказівника на початок списка
 - Циклічний прохід по елементам
 - Повернення покажчика на потрібний елемент

Аргументи:
 - dllist_t *list - список
 - size_t pos - індекс

 ---
 
```c
void push_dllist(dllist_t *list, backpack_t *element);
```

Призначення: Додавання елементу у список 

Опис роботи:
 - Встановлення покажчика отсаннього елменту списку на область памʼяті, де знаходиться той елемент, що потрібно додати

Аргументи:
 
 - dllist_t *list - список
 - backpack_t *element - елемент, що додаємо 
 ---
 
```c
void remove_from_dllist(dllist_t *list, size_t pos);
```

Призначення: Видалення елемента зі списку по індексу

Опис роботи:
 - Викликаємо функцію пошуку, яка поверне нам покажчик на той елемент, що потрібно видалити
 - Звертаємося до сусідніх елементів
 - Звільняємо пам'ять

Аргументи:
 - dllist_t *list - список 
 - size_t pos - індекс
 
 ---
 
```c
void write_to_file(dllist_t *list, const char *filename);
```

Призначення: Запис полів структур списка у файл

Опис роботи:
 - Запис у файл у текстовому вигляді

Аргументи:
 - dllist_t *list - список
 - const char *filename - ім'я файлу
 
---

```c
void read_from_file(dllist_t *list, const char *filename);
```
Призначення: Читання структур списка з файлу

Опис роботи:
 - Зчитує поля списку у текстовому вигляді з файлу

Аргументи:
 - dllist_t *list - список
 - const char *filename - ім'я файлу

---

```c
void print_dllist(dllist_t *list);
```
Призначення: Виведення списку у консоль

Опис роботи:
 - Виводить список у консоль

Аргументи:
 - dllist_t *list - список

---

```c
void sort_by_volume_dllist(dllist_t *list);
```
Призначення: Сортування елементів списку за зростанням по об'єму рюкзака

Опис роботи:
 - Сортує список шляхом обміну покажчиків

Аргументи:
 - dllist_t *list - список

```c
backpack_t  *get_backpack_from_user();
```
Призначення: Заповнення структури користувачем для додавання її у список

Опис роботи:
 - Отримує інформацію за допомогою scanf
 - Повертає вказівник на область памʼяті, в якій знаходиться потрібна структура

```c
void time_now();
```
Призначення: Виведення на єкран поточної дати та часу

Опис роботи:
 - Виводить на єкран дату та час

```c
int regex_scan_field(const char* str, const char* pattern)
```
Призначення: Перевірка на правильність внесених даних

Опис роботи:
- порівнює данні зі зразком за допомогою регулярних виразів

```c
void print_error(int problem)
```
Призначення: Друкування типу помилки у консоль

```c
int regex_has_two_words(char *str)
```

Призначення: Виявлення рядка, що має якнайменьше 2 слова  
```c
int has_two_words(backpack_t *current)
```

Призначення: Виявлення елмента, що має в собі хоча в одне поле, що містить 2 слова

```c
void print_two_words(dllist_t *list)
```

Призначення: Друкування елеменів, що мають хоча б один рядок, що містить 2 слова


**Блок схеми алгоритму**

- Схема звільнення памʼяті(див рис 1)

![](assets/block.PNG)

_Рисунок 1 - схема алгоритму_ 
 

### 2.3 Важливі фрагменти коду 

**Макровизначення**
```c
#define PUSH 1 - додавання у список
#define FIND 2 - знаходження елемента
#define REMOVE 3 - видалення зі списку
#define PRINT 4 - виведення списку у консоль
#define SORT 5 - сортування списку
#define FWRITE 6 - запис у файл
#define FREAD 7 - читання з файлу
#define EXIT 8 - вихід
#define INCORRECT 0 - некоректна операція

#define TYPE_ERROR 1 - слово починається з маленької букви або містить недопустимі символи 
#define BINARY_ERROR 2 - вираз повинен містити лише 0 або 1
#define DIGIT_ERROR 3 - число повинно складатися з 2 або більше цифр

```

**Структури даних**

- Структура для бренда

```c
typedef struct brand
{
	char name[15];
	char country[15];
}brand_t;
```
- Структура для рюкзака
```c
typedef struct backpack
{
	char laptop_compartment[4];
	char color[10];
	int volume;
	brand_t brand_1;
	char appointment[10];
}backpack_t;
```
- Структура для елементу списка
```c
typedef struct element element_t;

struct element {
	backpack_t data;
	element_t *next;
	element_t *prev;
};
```
- Стуктура для двузвʼязного списку

```c
typedef struct dllist {
	element_t *head;
	element_t *tail;
	size_t size;
} dllist_t;
```
- Додавання елементу

```c

void push_dllist(dllist_t *list, backpack_t *element)
{
	print_func_name(__FUNCTION__);
	element_t *prev;

	element_t *insert;

	if (!list || !element)
		return;

	if (list->tail == NULL)
	{
		insert = list->head = list->tail = malloc(sizeof(element_t));
		if (list->head == NULL)
			return;

		insert->prev = insert->next = NULL;

		memcpy(&insert->data, element, sizeof(backpack_t));
	}
	else
	{
		prev = list->tail;

		insert = prev->next = malloc(sizeof(element_t));
		if (prev->next == NULL)
		{
			return;
		}

		insert->prev = prev;
		insert->next = NULL;

		list->tail = insert;

		memcpy(&insert->data, element, sizeof(backpack_t));
	}
	list->size++;
}
```
 - Звільнення памʼяті

```c
void free_dllist(dllist_t **list)
{
	if (list != NULL && *list != NULL && (*list)->size != 0)
	{
		/* Get last element */
		element_t *iter = (*list)->tail;
		/* Delete all elements */
		while (iter->prev != NULL)
		{
			iter = iter->prev;
			free(iter->next);
		}
		free(iter);
		free(*list);
		*list = NULL;
	}
	return;
}
```
 - Видалення елемента
```c
void remove_from_dllist(dllist_t *list, size_t pos)
{
	print_func_name(__FUNCTION__);
	element_t *element;

	if (list == NULL)
	{
		printf("Can't remove\n");
		return;
	}

	if (list->size == 0 || pos >= list->size)
		return;
	element = find_in_dllist(list, pos);

	if (list->size == 1)
		list->head = list->tail = NULL;
	else if (pos == 0)
	{
		element->next->prev = NULL;
		list->head = element->next;
	}
	else if (pos == list->size - 1)
	{
		element->prev->next = NULL;
		list->tail = element->prev;
	}
	else
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	free(element);
	list->size--;
}
```
- Перевірка рядка за допомогою регулярних виразів
```c
int regex_scan_field(const char* str, const char* pattern)
{	
	regex_t regex;
	
	int result = 0; 
	
	if(result = regcomp(&regex, pattern, REG_EXTENDED))
	{
		printf("Can't create regex");
		return result;
	}
	result = regexec(&regex, str, 0, NULL, 0);

	return result;
}
```
### Перевірка наявності помилок витоків пам'яті(див рис 2)

![](assets/valgrind.PNG)

_Рисунок 2 - перевірка витоків пам'яті за допомогою valgrind_

### Результат модульного тестування

![](assets/test.PNG)

_Рисунок 3 - тестування_

## 3 Варіанти використання

**Результат роботи программи(див рис 4, рис 5, рис 6)**

![](assets/work.PNG)

_Рисунок 4 - Додавання елемента з перевіркою regex_

![](assets/work(2).PNG)

_Рисунок 5 - виведення всіх елементів_

![](assets/work(3).PNG)

_Рисунок 6 - виведення елементів, що мають два слова_

### Інстуркція щодо використання 

- make run - для запуску програми

## Висновок:

### В умовах даної лабраторної роботи було набуто практичного досвіду із роботою з регулярними виразами 