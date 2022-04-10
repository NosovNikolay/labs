#include "ClothBackpack.hpp"
#include <fstream>
#include <regex>

class CBarray
{
private:
    
    unsigned size;

    ClothBackpack** array;
    
    const int max_size = 10;
    
public:

    ~CBarray();

    CBarray();

    ClothBackpack* GetClothBackpack(unsigned index) const;

    ClothBackpack* GetClothBackpackWithLowestVolume() const;

    void Print();

    void AddElement(ClothBackpack* backpack);

    void DeleteElement(unsigned index);

    void DeleteAll();

    void ReadFromFile(string file_name);

    void WriteToFile(string file_name);

    ClothBackpack* operator[](unsigned index) const;

    friend std::ostream& operator<<(std::ostream& out, const CBarray& array);

    friend std::istream& operator>>(std::istream& in, CBarray& array);

    unsigned getSize()
    {
        return this->size;
    }

};




