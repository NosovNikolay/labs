#include "barray.hpp"
// Constructor with parametr
Barray::Barray(const unsigned int max_size_)
    :size(0),
    array(new Backpack*[(max_size_ == 0) ? 1 : max_size_]),
    max_size((max_size_ == 0 ? 1 : max_size_)){
}
// Destructor
Barray::~Barray(){
  
  while (size > 0){
    DeleteElement(size - 1);
  }
  
  delete[] array;
}

Backpack* Barray::GetBackpack(unsigned int index) const{
    if(index > size)
        return nullptr;
    return array[index];
}

Backpack* Barray::GetBackpackWithLowestVolume() const{
    
    if(size == 0)
        return nullptr;
    
    Backpack* min = *(array);

    if(size == 1)
        return* array;

    for(unsigned int i = 1; i < size; i++){
        if((*(array + i))->GetVolume() < min->GetVolume())
            min = *(array + i);
    }
    return min;
}

void Barray::Print()
{
    Backpack* tmp;

    for(unsigned int i = 0; i < size; i++){
        tmp = *(array + i);
        cout << i + 1 << ") ";
        cout << tmp->GetBrand()->city.c_str() << "\t";
        cout << tmp->GetBrand()->country.c_str() << "\t";
        cout << tmp->GetBrand()->name_brand.c_str() << "\t" ;
        cout << tmp->GetColor().c_str() << "\t";
        cout << tmp->GetAppointment().c_str() << "\t";
        cout << (tmp->GetLaptopComparament() ? "Yes" : "No") << "\t";
        cout << tmp->GetVolume() << "\n";
    }
}

void Barray::AddElement(Backpack* backpack){
    
    if(size == max_size)
        return;
         
    *(array + size) = backpack;
    
    size++;
    
    return;
}

void Barray::DeleteElement(unsigned int index){

    if(index > size)
        return; 
    
    delete *(array + index);
    --size;

    while (index < size)
    {
        *(array + index) = *(array + index + 1);
        ++index;
    }
    *(array + index) = nullptr;
}