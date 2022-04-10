#include "LeatherBackpack.hpp"
#include "ClothBackpack.hpp"
#include "BArray.hpp"
int main()
{
    ClothBackpack backpack_2("Blue", "Urban", 1 , 10, true, Cotton, Brand("Ua","Kh","Adidas"));
    
    LeatherBackpack backpack_1("Blue", "Urban", 1 , 10, true, Smooth, Brand("Ua","Kiev","Nike"));

    BArray arr;
    
    arr.AddElement(backpack_2);

    arr.AddElement(backpack_1);

    arr.Print();
}