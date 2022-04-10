#include "BArray.hpp"
#include "LeatherBackpack.hpp"
#include "ClothBackpack.hpp"
unsigned test_operator_index()
{
    unsigned result = 1;

    LeatherBackpack backpack("Blue", "Urban", 1 , 10, true, Smooth, Brand("Ua","Kiev","Nike"));

    BArray array;

    array.AddElement(backpack);

    result = *array[0] == backpack;

    if (!result)
    {
        cout << "ERROR[" << __FUNCTION__ << "] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    return result;
}

unsigned test_operator_equal()
{
    unsigned result = 1;

    ClothBackpack backpack1("Blue", "Urban", 1 , 10, true, Cotton, Brand("Ua","Kh","Adidas"));
    ClothBackpack backpack2("Blue", "Urban", 1 , 10, true, Cotton, Brand("Ua","Kh","Adidas"));
    ClothBackpack backpack3("Blue", "Urban", 1 , 10, true, Synthetic, Brand("UA","Kh","Adidas"));

    result &= backpack1 == backpack1;

    if (!result)
    {
        cout << "ERROR[" << __FUNCTION__ << "] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    result &= backpack1 == backpack2;

    if (!result)
    {
        cout << "ERROR[" << __FUNCTION__ << "] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    result &= !(backpack1 == backpack3);

    if (!result)
    {
        cout << "ERROR[" << __FUNCTION__ << "] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    return result;
}
unsigned test_operator_assing()
{
    unsigned result = 1;

    LeatherBackpack backpack1("Blue", "Urban", 1 , 10, true, Smooth, Brand("Ua","Kh","Adidas"));
    LeatherBackpack backpack2("Blue", "Urban", 1 , 10, true, Smooth, Brand("Ua","Kh","Adidas"));

    backpack1 = backpack2;

    result &= backpack2 == backpack1;

    if (!result)
    {
        cout << "ERROR[" << __FUNCTION__ << "] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }
    return result;
}


int main()
{
    unsigned result = 1;

    result &= test_operator_index();

    result &= test_operator_assing();

    result &= test_operator_equal();

    if (result)
        cout << "All tests are passed" << endl;
    else
        cout << "Some tests are not passed" << endl;

    return 0;
}