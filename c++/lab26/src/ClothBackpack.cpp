#include "ClothBackpack.hpp"
ClothBackpack::ClothBackpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    bool waterproof,
    ClothType cloth,
    const Brand &brand_)
    {
        Backpack(color_,appointment_, laptop_comparament_, volume_, brand_);
        this->waterproof = waterproof;
        this->cloth = cloth;
    }
bool ClothBackpack::getWaterproof()
{
    return waterproof;
}
ClothType ClothBackpack::getCloth()
{
    return cloth;
}
void ClothBackpack::setCloth(ClothType cloth)
{
    this->cloth = cloth;
}
void ClothBackpack::setWaterproof(bool waterproof)
{
    this->waterproof = waterproof;
}
ClothBackpack *ClothBackpack::FillFromString(string str)
{
    string name_;

    string country_;

    string city_;

    string color_;

    string appointment_;

    bool laptop_comparament_;

    unsigned volume_;

    int cloth__;

    bool waterproof_;

    stringstream string_s(str);

    if (!(string_s >> color_ && string_s >> appointment_ &&
          string_s >> laptop_comparament_ && string_s >> volume_ &&
          string_s >> country_ && string_s >> city_ && string_s >> name_ >> cloth__ >> waterproof_))
    {
        return nullptr;
    }

    ClothType cloth_;
    switch (cloth__)
    {
    case 0:
        cloth_ = Synthetic;
        break;
    case 1:
        cloth_ = Tarpaulin;
        break;
    case 2:
        cloth_ = Wool;
        break;
    case 3:
        cloth_ = Cotton;
        break;
    }

    return new ClothBackpack(color_, appointment_, laptop_comparament_, volume_, waterproof_, cloth_,
                            Brand(country_, city_, name_));
}

string ClothBackpack::ToString()const
{
    stringstream string_s;

    string_s << color << appointment << laptop_comparament << volume << waterproof << cloth << brand->country << brand->city << brand->name_brand;

    return string_s.str();

}
