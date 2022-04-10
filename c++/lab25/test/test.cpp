#include "barray.hpp"
unsigned test_operator_index()
{
    unsigned result = 1;

    Backpack backpack("Blue","Urban",1, 10 , Brand("Ua","Kh","Nike"));

    Barray array(1);

    array.AddElement(&backpack);

    result = *array[0] == backpack;

    if(!result)
    {
        cout <<"ERROR[" << __FUNCTION__ <<"] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    return result;
}

unsigned test_operator_equal()
{
    unsigned result = 1;

    Backpack backpack1("Blue","Urban",1, 10 , Brand("Ua","Kh","Nike"));
    Backpack backpack2("Blue","Urban",1, 10 , Brand("Ua","Kh","Nike"));
    Backpack backpack3("Black","Urban",1, 110 , Brand("RU","MOW","Adidas"));

    result &= backpack1 == backpack1;

    if(!result)
    {
        cout <<"ERROR[" << __FUNCTION__ <<"] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    result &= backpack1 == backpack2;
    
    if(!result)
    {
        cout <<"ERROR[" << __FUNCTION__ <<"] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    result &= !(backpack1 == backpack3);

    if(!result)
    {
        cout <<"ERROR[" << __FUNCTION__ <<"] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }

    return result;

}
unsigned test_operator_assing()
{
    unsigned result = 1;

    Backpack backpack1("Blue","Urban",1, 10 , Brand("Ua","Kh","Nike"));
    Backpack backpack2("Black","Urban",0, 100 , Brand("Ua","Kh","Nike"));

    backpack1 = backpack2;

    result &= backpack2 == backpack1;

    if(!result)
    {
        cout <<"ERROR[" << __FUNCTION__ <<"] TI DEBIL, PEREPISIVAI" << endl;
        return result;
    }
    return result;

}

unsigned test_fill_from_string()
{
    unsigned result = 1;

    Backpack* tmp = Backpack::FillFromString("");

    if(tmp)
    {
        result = 0;
        delete tmp;
        return result;
    }

    tmp = Backpack::FillFromString("Yellow Urban 1 9 Ukraine Kharkov Adidas");

    if(!tmp)
    {
        result = 0;
        return result;
    }

    result &= (tmp->GetColor() == "Yellow");
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] color indicated incorrectly" << endl;
        return result;
    }

    result &= (tmp->GetAppointment() == "Urban");
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] appointment indicated incorrectly" << endl;
        return result;
    }

    result &= (tmp->GetLaptopComparament());
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] laptop comparament indicated incorrectly" << endl;
        return result;
    }

    result &= (tmp->GetBrand().country == "Kharkov");
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] city indicated incorrectly" << endl;
        return result;
    }
    result &= (tmp->GetBrand().city == "Ukraine");
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] country indicated incorrectly" << endl;
        return result;
    }
    result &= (tmp->GetBrand().name_brand == "Adidas");
    if(!result)
    {
        cout << "Test failed [" << __FUNCTION__ << "] name of the brand indicated incorrectly" << endl;
        return result;
    }
    return result;
}

unsigned test_to_string()
{
    Backpack* backpack = Backpack::FillFromString("Yellow Urban 1 9 Ukraine Kharkov Adidas");

    if(backpack->ToString() == "YellowUrban19KharkovUkraineAdidas")
        return 1;
    return 0;
}

int main()
{
    unsigned result = 1;

    result &= test_fill_from_string();

    result &= test_to_string();

    //result &= test_operator_index();

    result &= test_operator_assing();

    result &= test_operator_equal();

    if(result)
        cout << "All tests are passed" << endl;
    else
        cout << "Some tests are not passed" << endl;

    return 0;
}