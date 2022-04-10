// Lab №23 - OOP
// Nosov M.V
// 08.05.2021


#include "barray.hpp"
int main(void)
{
    Barray array;
    /// Create 3 elements      
    array.AddElement(new Backpack("Blue","Urban", 1, 10, Brand("Ukraine","Kharkov","Adidas")));
    array.AddElement(new Backpack("Black","Urban", 0, 15, Brand("Ukraine","Kharkov","Adidas")));
    array.AddElement(new Backpack("Yellow","Urban", 1, 11, Brand("Ukraine","Kharkov","Adidas")));
    // Print all
    
    array.Print();    
    // Delete second element
    array.DeleteElement(1);

    // Print all again
    array.Print();

    // Print with the lowest volume
    Backpack *min;

    min = array.GetBackpackWithLowestVolume();

    cout << " Min volume is :" <<min->GetVolume() << endl;
    return 0;
}