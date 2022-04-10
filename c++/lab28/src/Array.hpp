/// @file Array.hpp
/// @brief Arrays from file, find maximal value of every array
///
/// @author Nosov M
/// @version 1.0
/// @date 2-june-2021

#ifndef ARRAY
#define ARRAY
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <new>
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;

class Array {
private:
	
	int arraysCount;

	int **arrays;

	int *max;

public:
	
	Array() noexcept;
	
	~Array() noexcept;
	
	void addElements(string h, int count);
	
	void readFromFile(string fileName);

	void writeToFile(string fileName);

	void findMax();

	int elementById(int count, int id) const;

	void setSize(int s);

	void memAllocate();
};

#endif 
