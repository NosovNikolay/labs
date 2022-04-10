// Lab №23 - OOP
// Nosov M.V
// 08.05.2021


#include "barray.hpp"
int main(void)
{
    Backpack backpack_1("Red","Urban", 1, 10, Brand("H","H","H"));

    Backpack backpack_2("Yellow","Mil", 0, 10, Brand("F","F","F"));

    Backpack backpack_3("Black","Urban", 1, 10, Brand("C","C","C"));

    struct Brand tmp = backpack_1.GetBrand();

    backpack_1 = backpack_2 = backpack_3;

    bool result = backpack_1 == backpack_2;

    if(result)
    {
        cout << "Overload is working!" << endl;
    }

    cout << backpack_3 << endl;
    
    Backpack backpack_4;

    //std::cin >> backpack_4;

    //cout << backpack_4 << endl;

    //Backpack *tmp_ = Backpack::FillFromString("Blue Urban 1 15 Ua Kh Nike");

    Barray array(4);

    //array.AddElement(&backpack_1);

    std::cin >> array;

    array.Print();

    return 0;
}