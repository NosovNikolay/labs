// Nosov M 
// CIT 120 b
// 02.06.2021 1:40 -_______-
// Lab 28
#include "Array.hpp"

/// Головна функція
///
/// Послідовність дій:
/// - введення з клавіатури вхідного файлу з даними;
/// - читання даних з файлу;
/// - виконання індивідуального завдання;
/// - введення з клавіатури вихідного файлу;
/// - запис результату операції у файл;
///
/// @return Код успішного виходу з програми (0)

int main()
{
	Array current_array;
	
	string file;
	
	while (true)
	{
		cout << "Enter the file name please: ";
		
		cin >> file;
		
		if (file == "exit")
			break;
		
		try
		{
			current_array.readFromFile(file);
			current_array.findMax();

			cout << "Enter the name of file to write: ";
			cin >> file;

			current_array.writeToFile(file);
			cout << "Success!" << endl;
		}
		catch (const std::runtime_error &error)
		{
			cerr << "[ERROR]" << __FUNCTION__ << "-->Runtime error" << endl
				<< error.what() << endl;
			continue;
		}
		catch (const std::out_of_range &error)
		{
			cerr << "[ERROR]" << __FUNCTION__ << "-->Out of range" << endl 
				<< error.what() << endl;
			continue;
		}
		catch (const std::bad_alloc &error)
		{
			cerr << "[ERROR]" << __FUNCTION__ << "-->Bad memory allocate" << endl
				 << error.what() << endl;
			continue;
		}
		catch (...)
		{
			cerr << "[ERROR]" << __FUNCTION__ << endl;
		}
		cout << "Enter exit if you want to stop the programm" << endl;
	}
	cout << "Thank you for using out programm" << endl;
	
	return 0;
}
