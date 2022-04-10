#ifndef LeatherBackpack_H
#define LeatherBackpack_H
#include"Backpack.hpp"
enum leatherType{
    Smooth,
    Solid,
    Glossy,
    Matt,
    Artifical
};
class LeatherBackpack: public Backpack
{
private:
    bool have_lining;
    leatherType backpack_leather;

public:
    LeatherBackpack(string color_,
                   AppointmentType appointment_,
                   bool laptop_comparament_,
                   unsigned volume_,
                   bool have_lining,
                   leatherType backpack_leather,
                   const Brand &brand_);
    ~LeatherBackpack();
    std::string display() override {
        return "Backpack is Leather" + std::to_string(GetVolume());
    };
    virtual bool isLeather() override {
        return true;
    };
    virtual bool isCloth() override {
        return false;
    };
};

#endif