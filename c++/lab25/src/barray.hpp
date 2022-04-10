#include "backpack.hpp"
#include "brand.hpp"
#ifndef BARRAY_H
#define BARRAY_H
// Class for array of backpacks
class Barray
{
private:
    
    unsigned size;

    Backpack** array;
    
    const unsigned int max_size = 4;

    static const string regex_pattern;


public:

    Barray(const unsigned int max_size_);
    
    ~Barray();

    Backpack* GetBackpack(unsigned index) const;

    Backpack* GetBackpackWithLowestVolume() const;

    void Print();

    void AddElement(Backpack* backpack);

    void DeleteElement(unsigned index);

    void DeleteAll();

    void ReadFromFile(string file_name);

    void WriteToFile(string file_name);

    Backpack* operator[](unsigned index) const;

    friend std::ostream& operator<<(std::ostream& out, const Barray& array);

    friend std::istream& operator>>(std::istream& in, Barray& array);

    unsigned getSize()
    {
        return this->size;
    }

};

#endif