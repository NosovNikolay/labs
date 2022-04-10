#include "BArray.hpp"
BArray::BArray()
{
    size = 0;
    array = new Backpack *[max_size];
}

BArray::~BArray()
{
    DeleteAll();
    delete[] array;
}
bool BArray::AddElement(const Backpack &backpack)
{
    if (size == max_size)
        return false;

    array[size] = backpack.Copy();

    if (array[size] == nullptr)
        return false;

    size++;

    return true;
}

bool BArray::DeleteElement(unsigned index)
{
    if (index >= size)
        return false;
    delete array[index];

    for (; index < size - 1; index++)
    {
        array[index] = array[index + 1];
    }

    array[index] = nullptr;

    size--;

    return true;
}

Backpack *BArray::GetBackpackWithLowestVolume() const
{

    if (size == 0)
        return nullptr;

    //To safe pointer to element in cycle
    Backpack *min = *(array);

    if (size == 1)
        return *array;

    for (unsigned int i = 1; i < size; i++)
    {
        if ((*(array + i))->GetVolume() < min->GetVolume())
            min = *(array + i);
    }
    return min;
}

void BArray::Print()
{
    for (unsigned i = 0; i < size; i++)
    {
        cout << "[" << i << "]" << array[i]->ToString() << endl;
    }
}

//To delete elements before reading from file
void BArray::DeleteAll()
{
    if (size != 0)
    {
        for (unsigned i = 0; i < size; i++)
            delete array[i];
    }
    size = 0;
}

void BArray::WriteToFile(std::string filename)
{
    std::ofstream out(filename, std::ios_base::out);
    if (!out.is_open())
    {
        return;
    }
    for (unsigned i = 0; i < size; ++i)
    {
        out << "[ " << i << " ]: " << array[i]->ToString() << '\n';
    }

    out.close();
}
Backpack *BArray::operator[](unsigned index) const
{
    if (index >= size)
    {
        return nullptr;
    }

    return array[index];
}
unsigned BArray::GetSize()
{
    return this->size;
}
