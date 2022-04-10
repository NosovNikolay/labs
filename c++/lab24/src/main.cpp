// Lab №23 - OOP
// Nosov M.V
// 08.05.2021


#include "barray.hpp"
int main(void)
{
    Barray array;

    array.AddElement(new Backpack("Blue","Urban", 1, 10 ,Brand("Ukraine","Kharkov","Adidas")));

    array.AddElement(new Backpack("Black","Sport", 0, 15 ,Brand("Ukraine","Kharkov","Nike")));
    
    /// Create 2 elements    
    
    // Print all
    cout << "Print 2 elements array" << endl;

    array.Print();
    
    Backpack* backpack = Backpack::FillFromString("Yellow Urban 1 9 Ukraine Kharkov Adidas");

    backpack->ToString(); 
    // Пихаю элемент в массив, что бы его сожрал дестркуктор
    array.AddElement(backpack);

    cout << "Add element from the string" << endl;

    array.Print();
   
    array.WriteToFile("dist/output.dat");
       
    Barray array_2;

    array_2.ReadFromFile("dist/input.dat");

    cout << "Fill massive from file and print it" << endl;

    array_2.Print();

    array_2.ReadFromFile("dist/input.dat");

    cout << "Print 1 more time" << endl;

    array_2.Print();

    return 0;
}