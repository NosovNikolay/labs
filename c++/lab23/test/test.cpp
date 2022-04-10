// Tests for general task
#include "barray.hpp"
unsigned test_get_min_volume(){
    
    cout << "Test running[" << __FUNCTION__ << "]..." << endl;
    
    Barray array;

    array.AddElement(
    new Backpack("Blue", "Ubran", 0, 20, 
    Brand("Ukraine","Kharkov", "Adibas")));

    if(array.GetBackpack(0) == nullptr){
        cout << "ERROR, can't add element" << endl;
        return 0;
    }

    array.AddElement(
    new Backpack("Blue", "Ubran", 0, 15, 
    Brand("Ukraine","Kharkov", "Adibas")));

    if(array.GetBackpack(1) == nullptr){
        cout << "ERROR, can't add element" << endl;
        return 0;
    }

    array.AddElement(
    new Backpack("Blue", "Ubran", 0, 10, 
    Brand("Ukraine","Kharkov", "Adibas")));
    
    if(array.GetBackpack(2) == nullptr){
        cout << "ERROR, can't add element" << endl;
        return 0;
    }

    Backpack* tmp = array.GetBackpackWithLowestVolume();

    if(tmp->GetVolume() != 10){
        cout << "ERROR, can't get minimal value" << endl;
        return 0;
    }
    return 1;
}

unsigned test_get_element(){
    
    cout << "Test running[" << __FUNCTION__ << "]..." << endl;
    
    Barray array;

    array.AddElement(
    new Backpack("Blue", "Ubran", 0, 20, 
    Brand("Ukraine","Kharkov", "Adibas")));

    if(array.GetBackpack(0) == nullptr){
        cout << "ERROR, can't add element" << endl;
        return 0;
    }

    array.DeleteElement(0);
    if(array.GetBackpack(0) != nullptr){
        cout << "ERROR, can't delete element" << endl;
        return 0;
    }

    return 1;
}
int main(){
    
    unsigned result = 1;

    result &= test_get_element();
    result &= test_get_min_volume();

    if(result)
        cout << "All tests are passed" << endl;
    else    
        cout << "Some tests are not passed" << endl; 
    
    return 0;
}