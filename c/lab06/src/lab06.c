#define T1_STRING "  Mama ya lublu teb9      " /**< Строка, которую нужно центрировать */
#define T1_FILLER '_' /**< Заполнитель */

#define T2_SIZE 1000000U 
#define T2_PRIMES_COUNT 30U 

#define T3_NUMBER 1911 
#define T3_MAX_SIZE 43 

#define T4_STRING "     So   much             spaaaaaaaaaaaaace		aaaaaaaaaaaaa." /**< Строка, в которой нужно подсчитать кол-во строк */
#define T4_STATE_IN 0U 
#define T4_STATE_OUT 1U 

#define T5_MASSIVE {{5, 1, 0}, {4, 2, 3}, {3, 0, 1}} /**< Массив, который нужно сдвинуть */
#define T5_N 3U /**< Размер квадратного массива, который нужно сдвинуть */

#define T6_MATRIX {{-3, 2, -4}, {0, 5, -3}, {6, 1, -1}} /**< Матрица, которую нужно возвести в квадрат */
#define T6_N 3U /**< Размер квадратной матрицы, которую нужно возвести в квадрат */

int main(void)
{
	/* --- Задание 1 --- */
	{
		char string[] = T1_STRING; 
		unsigned int string_size; 
		unsigned int posLeft; 
		unsigned int textSize; 
		unsigned int i, k; 
		
		
		for(i = 0; string[i] == ' '; ++i)
			;
		posLeft = i;
		for(; string[i] != '\0'; ++i)
			;
		string_size = i;
		for(i -= 1; string[i] == ' '; --i)
			;
		textSize = i - posLeft + 1;
		
		char result[string_size + 1];
		for(i = 0; i < (string_size - textSize) / 2; ++i)
			result[i] = T1_FILLER;
		
		for(k = posLeft; k < posLeft + textSize;)
			result[i++] = string[k++];
		
		for(; i < string_size; ++i)
			result[i] = T1_FILLER;
		result[string_size] = '\0';
	}
	
	/* --- Задание 2 --- */
	{
		unsigned long long primes[T2_SIZE] = { 0 };
		unsigned int need_to_find = T2_PRIMES_COUNT; 
		primes[0] = 2; 
		unsigned int primes_found = 1; 
		unsigned int i; 
		unsigned long long curr; 
		
		for(curr = 3U; primes_found < need_to_find; ++curr)
		{
			for(i = 0; primes[i] * primes[i] <= curr; ++i)
			{
				if(curr % primes[i] == 0)
					break;
			}
			if(primes[i] * primes[i] > curr)
				primes[primes_found++] = curr;
		}
	}
	
	/* --- Задание 3 --- */
	{
		char digit_name[][13] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen" };
		char decade_name[][8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
		char th_name[] = "thousand";
		char hd_name[] = "hundred";
		char tn_name[] = "teen";
		unsigned short number = T3_NUMBER; 
		char string[T3_MAX_SIZE]; 
		unsigned short i = 0; 
		unsigned short k; 
		unsigned short digit; 
		
		digit = number / 1000;
		if(digit)
		{
			/* Копируем цифру в массив */
			for(k = 0; digit_name[digit][k] != '\0';)
				string[i++] = digit_name[digit][k++];
			string[i++] = ' ';
			/* Копируем слово тысячи */
			for(k = 0; th_name[k] != '\0';)
				string[i++] = th_name[k++];
			string[i++] = ' ';
		}
		
		digit = number % 1000 / 100;
		if(digit)
		{
			/* Копируем цифру в массив */
			for(k = 0; digit_name[digit][k] != '\0';)
				string[i++] = digit_name[digit][k++];
			string[i++] = ' ';
			/* Копируем слово сотни */
			for(k = 0; hd_name[k] != '\0';)
				string[i++] = hd_name[k++];
			string[i++] = ' ';
		}
		
		digit = number % 100;

		if(digit == 0 && i == 0)
		{
			for(k = 0; digit_name[digit][k] != '\0';)
				string[i++] = digit_name[digit][k++];
		}
		
		else if(digit > 0 && digit <= 13)
		{
			for(k = 0; digit_name[digit][k] != '\0';)
				string[i++] = digit_name[digit][k++];
		}
		else if(digit >= 14 && digit <= 19)
		{
			digit = digit % 10 - 1;
			/* Копируем цифру в массив */
			for(k = 0; digit_name[digit][k] != '\0';)
				string[i++] = digit_name[digit][k++];
			/* Копируем приставку 'teen' */
			for(k = 0; tn_name[k] != '\0';)
				string[i++] = tn_name[k++];
		}
		else if(digit >= 20)
		{
			digit = number % 100 / 10 - 2;
			for(k = 0; decade_name[digit][k] != '\0';)
				string[i++] = decade_name[digit][k++];
			
			/* Если есть единицы */
			digit = number % 10;
			if(digit)
			{
				string[i++] = '-';
				/* Копируем единицы */
				for(k = 0; digit_name[digit][k] != '\0';)
					string[i++] = digit_name[digit][k++];
			}
		}
		
		string[i] = '\0';
	}
	
	/* --- Задание 4 --- */
	{
		char string[] = T4_STRING; 
		unsigned int i; 
		unsigned int word_count = 0;
		unsigned char state = T4_STATE_OUT; 
		
		for(i = 0; string[i] != '\0'; ++i)
		{
			if(state == T4_STATE_OUT && string[i] != ' ' && string[i] != '\t')
			{
				state = T4_STATE_IN;
				++word_count;
			}
			else if(state == T4_STATE_IN && (string[i] == ' ' || string[i] == '\t'))
				state = T4_STATE_OUT;
		}
	}
	
	/* --- Задание 5 --- */
	{
		int massive[T5_N][T5_N] = T5_MASSIVE; 
		int temp_column[T5_N]; 
		unsigned char i; 
		unsigned char k; 

		for(k = 0; k < T5_N; ++k)
			temp_column[k] = massive[k][0];
		
		for(i = 0; i < T5_N - 1; ++i)
		{
			for(k = 0; k < T5_N; ++k)
			{
				massive[k][i] = massive[k][i + 1];
			}
		}
		
		for(k = 0; k < T5_N; ++k)
			massive[k][T5_N - 1] = temp_column[k];
	}
	
	/* --- Задание 6 --- */
	{
		int matrix[T6_N][T6_N] = T6_MATRIX;
		int result[T6_N][T6_N] = { 0 };
		unsigned char i; 
		unsigned char j; 
		unsigned char k; 

		for(i = 0; i < T6_N; ++i)
		{
			for(j = 0; j < T6_N; ++j)
			{
				for(k = 0; k < T6_N; ++k)
				{
					result[i][j] += matrix[i][k] * matrix[k][j];
				}
			}
		}
	}
	
	return 0;
}
