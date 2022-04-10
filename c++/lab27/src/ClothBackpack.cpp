#include "ClothBackpack.hpp"
ClothBackpack::~ClothBackpack()
{
}
ClothBackpack::ClothBackpack()
    : Backpack(), waterproof(false)
{
}
ClothBackpack::ClothBackpack(string color_,
                             string appointment_,
                             bool laptop_comparament_,
                             unsigned volume_,
                             bool waterproof_,
                             ClothType cloth_,
                             const struct Brand &brand_)
    : Backpack(color_, appointment_, laptop_comparament_,
               volume_, brand_),
      waterproof(waterproof_),
      cloth(cloth_)
{
}
string ClothBackpack::ToString() const
{

    std::stringstream string_s;

    string_s << endl
             << "Backpack : color-> " << color << endl
             << "Appointment-> " << appointment << endl
             << "Laptop comparament ->" << laptop_comparament << endl
             << "Volume is: " << volume << endl
             << "Waterproof ->" << waterproof << endl
             << "Cloth type ->" << cloth << endl
             << "Contry is:" << brand->country << endl
             << "City is: " << brand->city << endl
             << "Brand is: " << brand->name_brand << endl;

    return string_s.str();
}
bool ClothBackpack::FillFromString(string str)
{
    std::stringstream ss(str);

    int cloth = 0;

    if (!(ss >> color && ss >> appointment &&
          ss >> laptop_comparament && ss >> volume &&
          ss >> waterproof && ss >> cloth && 
          ss >> brand->country && ss >> brand->city && ss >> brand->name_brand))
        return false;
    return true;
}
Backpack *ClothBackpack::Copy() const
{
    ClothBackpack *result = new ClothBackpack();

    if (!result)
        return nullptr;

    *result = *this;
    return result;
}