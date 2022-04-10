#include "backpack.hpp"
// Constructor with parameters
Backpack::Backpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    const struct Brand& brand_)
    :color(color_),
    appointment(appointment_),
    laptop_comparament(laptop_comparament_),
    volume(volume_){
    brand = new struct Brand(brand_.city, brand_.country, brand_.name_brand);
}
// Copy constructor
Backpack::Backpack(const Backpack& current_backpack)
    :color(current_backpack.color),
    appointment(current_backpack.appointment),
    laptop_comparament(current_backpack.laptop_comparament),
    volume(current_backpack.volume){
    brand = new struct Brand(current_backpack.brand->city,
                            current_backpack.brand->country,
                            current_backpack.brand->name_brand);
}
// Destructor
Backpack::~Backpack(){
    if(brand != nullptr)
        delete brand;
}

unsigned int Backpack::GetVolume() const{
    return volume;
}

string Backpack::GetColor() const{
    return color;
}

string Backpack::GetAppointment() const{
    return appointment;
}

Brand* Backpack::GetBrand() const{
    return brand;
}

bool Backpack::GetLaptopComparament() const{
    return laptop_comparament;
}

void Backpack::SetAppointment(string appointment_){
    appointment = appointment_;
}

void Backpack::SetBrand(Brand* brand_) {

  if (brand != nullptr) {
    delete brand;
  }
  brand = brand_;
}

void Backpack::SetLaptopComparament(bool laptop_comparament_){
    laptop_comparament = laptop_comparament_;
}

void Backpack::SetVolume(unsigned volume_){
    volume = volume_;
}

void Backpack::SetColor(string color_){
    color = color_;
}