
#include "Array.hpp"

Array::Array() noexcept
	: arrays(nullptr),
	  max(nullptr)
{
}

Array::~Array() noexcept
{
	delete[] max;
	
	max = nullptr;
	
	for (int i = 0; i < arraysCount; i++)
		delete[] arrays[i];
	
	delete[] arrays;
	
}

void Array::setSize(int s)
{
	arraysCount = s;
}

void Array::addElements(string h, int count)
{
	std::stringstream str;
	
	int elem = 0;

	str.clear();
	str << h;
	str >> elem;
	
	arrays[count] = new int[elem + 1];
	arrays[count][0] = elem;
	
	for (int i = 1; i < elem + 1; i++)
	{
		if (!(str >> arrays[count][i]))
			throw std::runtime_error("Can't read this element");
	}
}

void Array::memAllocate()
{
	arrays = new int *[arraysCount];
	max = new int[arraysCount];
}

void Array::readFromFile(string fileName)
{
	std::ifstream in(fileName);
	
	std::stringstream str;
	
	string buff;
	int count = 0;
	
	if (!in.is_open())
		throw std::runtime_error("We can't find the file //" + fileName + "//");
	
	getline(in, buff);
	
	str.clear();
	
	str << buff;
	
	if (!(str >> arraysCount))
		throw std::runtime_error("We can't read the quantity of arrays");
	
	memAllocate();

	if(max == nullptr || arrays == nullptr)
	{
		throw std::bad_alloc();
	}
	
	while (count < arraysCount)
	{
		getline(in, buff);
		addElements(buff, count);
		count++;
	}
	in.close();
}


void Array::writeToFile(string fileName)
{
	std::ofstream out;

	out.open(fileName);

	int count = 0;

	if (!out.is_open())
		throw std::runtime_error("Can't find or create thi file :[" + fileName + "]");

	out << "Array --> maximum" << endl;

	while (count < arraysCount)
	{
		for (int i = 1; i < arrays[count][0] + 1; i++)
			out << arrays[count][i] << " ";
		
		out << "--> ";
		
		out << max[count] << endl;
		
		count++;
	}
	out.close();
}

void Array::findMax()
{
	int count = 0;
	while (count < arraysCount)
	{
		// Do not touch array size to find maximum
		int maximum = arrays[count][1];
		for (int i = 1; i < arrays[count][0] + 1; i++)
		{
			if (maximum < arrays[count][i])
				maximum = arrays[count][i];
		}
		max[count] = maximum;
		maximum = 0;
		count++;
	}
}

int Array::elementById(int count, int id) const
{
	if (count > arraysCount)
		throw std::out_of_range("Any array with this ID");
	else if (id > arrays[count][0])
		throw std::out_of_range("Any element with this ID");
	
	return arrays[count][id];
}
