// Lab №23 - OOP
// Nosov M.V
// 08.05.2021
#include "CBarray.hpp"
#include "Barray.hpp"
#include "LBarray.hpp"
int main(void)
{
    ClothBackpack current_("Blue", "Urban", 1, 10, 1, Cotton, Brand("Ua","Kh","Nike"));

    ClothBackpack current_2 = current_;

    current_2.SetVolume(15);

    ClothBackpack current_3 = ClothBackpack(current_2);

    current_3.SetVolume(20);

    CBarray array_c;    

    array_c.AddElement(&current_);

    array_c.AddElement(&current_2);

    array_c.AddElement(&current_3);

    cout << array_c.GetClothBackpackWithLowestVolume() << endl;
    
    LeatherBackpack current_4("Blue", "Urban", 1, 10, 1, Smooth, Brand("Ua","Kh","Adidas"));

    LeatherBackpack current_5 = current_4;

    current_5.SetVolume(15);

    LBarray array_l;

    array_l.AddElement(&current_4);

    array_l.AddElement(&current_5);

    cout << array_l.GetLeatherBackpackWithLowestVolume() << endl;

    return 0;
}