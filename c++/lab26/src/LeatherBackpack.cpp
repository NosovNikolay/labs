#include "LeatherBackpack.hpp"
LeatherBackpack::LeatherBackpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    bool has_lining_,
    leatherType leather,
    const Brand &brand_)
{
    Backpack(color_,appointment, laptop_comparament_, volume_, brand_);
    this->backpack_leather = leather;
    this->has_lining = has_lining_;
}
leatherType LeatherBackpack::getLeatherType()
{
    return backpack_leather;
}
bool LeatherBackpack::getLining()
{
    return has_lining;
}

void LeatherBackpack::setLining(bool lining)
{
    this->has_lining = lining;
}

void LeatherBackpack::setLeather(leatherType leather)
{
    this->backpack_leather = leather;
}
LeatherBackpack *LeatherBackpack::FillFromString(string str)
{
    string name_;

    string country_;

    string city_;

    string color_;

    string appointment_;

    bool laptop_comparament_;

    unsigned volume_;

    int leather__;

    bool has_lining_;

    stringstream string_s(str);

    if (!(string_s >> color_ && string_s >> appointment_ &&
          string_s >> laptop_comparament_ && string_s >> volume_ &&
          string_s >> country_ && string_s >> city_ && string_s >> name_ >> leather__ >> has_lining_))
    {
        return nullptr;
    }

    leatherType leather_;
    switch (leather__)
    {
    case 0:
        leather_ = Smooth;
        break;
    case 1:
        leather_ = Solid;
        break;
    case 2:
        leather_ = Glossy;
        break;
    case 3:
        leather_ = Matt;
        break;
    }

    return new LeatherBackpack(color_, appointment_, laptop_comparament_, volume_, has_lining_, leather_,
                            Brand(country_, city_, name_));
}
string LeatherBackpack::ToString()const
{
    stringstream string_s;

    string_s << color << appointment << laptop_comparament << volume << has_lining << backpack_leather << brand->country << brand->city << brand->name_brand;

    return string_s.str();

}