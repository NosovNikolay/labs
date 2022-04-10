#include "LeatherBackpack.hpp"
LeatherBackpack::LeatherBackpack() {}

LeatherBackpack::~LeatherBackpack() {}

Backpack *LeatherBackpack::Copy() const
{
  LeatherBackpack *result = new LeatherBackpack();
  if (result == nullptr)
  {
    return nullptr;
  }

  *result = *this;
  return result;
}
LeatherBackpack::LeatherBackpack(string color_,
                                 string appointment_,
                                 bool laptop_comparament_,
                                 unsigned volume_,
                                 bool has_lining_,
                                 leatherType leather_,
                                 const struct Brand &brand_)
    : Backpack(color_, appointment_, laptop_comparament_,
               volume_, brand_),
      leather(leather_),
      has_lining(has_lining_)
{
}
string LeatherBackpack::ToString() const
{
  stringstream string_s;

  string_s << endl
           << "Backpack : color-> " << color << endl
           << "Appointment-> " << appointment << endl
           << "Laptop comparament ->" << laptop_comparament << endl
           << "Volume is: " << volume << endl
           << "Has lining ->" << has_lining << endl
           << "Leather type ->" << leather << endl
           << "Contry is:" << brand->country << endl
           << "City is: " << brand->city << endl
           << "Brand is: " << brand->name_brand << endl;

  return string_s.str();
}
bool LeatherBackpack::FillFromString(string str)
{
    std::stringstream ss(str);

    int leather = 0;

    if (!(ss >> color && ss >> appointment &&
          ss >> laptop_comparament && ss >> volume &&
          ss >> has_lining && ss >> leather && 
          ss >> brand->country && ss >> brand->city && ss >> brand->name_brand))
        return false;
    return true;
}