#include "barray.hpp"
#include <fstream>
#include <regex>
const std::string RegexPattern = "[A-Za-z]*\\s[A-Za-z]*\\s[01]*\\s[0-9]*\\s[A-Za-z]*\\s[A-Za-z]*\\s[A-Za-z]*";
// Constructor with parametr
Barray::Barray(const unsigned int max_size_)
    : size(0),
      array(new Backpack *[(max_size_ == 0) ? 1 : max_size_]),
      max_size((max_size_ == 0 ? 1 : max_size_))
{
}
// Destructor
Barray::~Barray()
{

    DeleteAll();

    delete[] array;
}

Backpack *Barray::GetBackpack(unsigned int index) const
{
    if (index > size)
        return nullptr;
    return array[index];
}

Backpack *Barray::GetBackpackWithLowestVolume() const
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

void Barray::Print()
{
    Backpack *tmp;

    for (unsigned int i = 0; i < size; i++)
    {
        tmp = *(array + i);
        cout << i + 1 << ") ";
        cout << tmp->GetBrand().city.c_str() << "\t";
        cout << tmp->GetBrand().country.c_str() << "\t";
        cout << tmp->GetBrand().name_brand.c_str() << "\t";
        cout << tmp->GetColor().c_str() << "\t";
        cout << tmp->GetAppointment().c_str() << "\t";
        cout << (tmp->GetLaptopComparament() ? "Yes" : "No") << "\t";
        cout << tmp->GetVolume() << "\n";
    }
}

void Barray::AddElement(Backpack *backpack)
{

    if (size == max_size)
        return;

    *(array + size) = backpack;

    size++;

    return;
}

void Barray::DeleteElement(unsigned int index)
{

    if (index > size)
        return;

    delete *(array + index);
    --size;

    while (index < size)
    {
        *(array + index) = *(array + index + 1);
        ++index;
    }
    *(array + index) = nullptr;
}
//To delete elements before reading from file
void Barray::DeleteAll()
{
    if(size != 0 ){
    for (unsigned i = 0; i < size; i++)
        delete array[i];
    size = 0;
    }
}

void Barray::WriteToFile(std::string filename)
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
void Barray::ReadFromFile(string filename)
{

    std::ifstream in(filename, std::ios_base::in);
    string line;

    if (!in.is_open())
    {
        return;
    }
    if (size != 0)
    {
        DeleteAll();
    }
    Backpack *tmp;
    while (size != max_size && std::getline(in, line))
    {
        tmp = Backpack::FillFromString(line);
        if (tmp != nullptr)
        {
            AddElement(tmp);
        }
    }
    delete tmp;
    in.close();
}
Backpack* Barray::operator[](unsigned index) const
{
  if (index >= size) {
    return nullptr;
  }

  return array[index];
}
std::istream& operator>>(std::istream& in, Barray& array)
{
    Backpack* tmp;
    string line;
    std::regex regex(RegexPattern);
    std::smatch matches;

    if(array.getSize() != 0)
    {
         array.DeleteAll();
     }

    if(std::getline(in, line) && std::regex_match(line, matches, regex) && (tmp = Backpack::FillFromString(line)) != nullptr)
    {
        array.AddElement(tmp);
        //delete tmp;
    }
    else{
        cout << "ERROR" << endl;
    }
    return in;
}
