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
    
    const unsigned int max_size;

public:
    
    Barray(const unsigned int max_size_ = 3);
    
    ~Barray();

    Backpack* GetBackpack(unsigned index) const;

    Backpack* GetBackpackWithLowestVolume() const;

    void Print();

    void AddElement(Backpack* backpack);

    void DeleteElement(unsigned index);
};

#endif