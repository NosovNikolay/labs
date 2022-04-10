#include"Backpack.hpp"
#include <iostream>
#include <fstream>
class BArray
{
private:

    Backpack** array;

    const unsigned max_size = 10;

    unsigned size;

public:
    
    BArray();

    Backpack* GetBackpack(unsigned index) const;

    Backpack* GetBackpackWithLowestVolume() const;

    void Print();

    bool AddElement(const Backpack& backpack);

    bool DeleteElement(unsigned index);

    void DeleteAll();

    void ReadFromFile(string file_name);

    void WriteToFile(string file_name);

    Backpack* operator[](unsigned index) const;

    friend std::ostream& operator<<(std::ostream& out, const BArray& array);

    friend std::istream& operator>>(std::istream& in, BArray& array);

    unsigned GetSize();

    ~BArray();
};



