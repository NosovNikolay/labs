#include "LeatherBackpack.hpp"
class LBarray
{
private:
    
    unsigned size;

    LeatherBackpack** array;
    
    const int max_size = 10;
    
public:

    ~LBarray();

    LBarray();

    LeatherBackpack* GetLeatherBackpack(unsigned index) const;

    LeatherBackpack* GetLeatherBackpackWithLowestVolume() const;

    void Print();

    void AddElement(LeatherBackpack* backpack);

    void DeleteElement(unsigned index);

    void DeleteAll();

    void ReadFromFile(string file_name);

    void WriteToFile(string file_name);

    LeatherBackpack* operator[](unsigned index) const;

    friend std::ostream& operator<<(std::ostream& out, const LBarray& array);

    friend std::istream& operator>>(std::istream& in, LBarray& array);

    unsigned getSize()
    {
        return this->size;
    }

};