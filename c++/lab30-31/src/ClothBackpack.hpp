#include "Backpack.hpp"
enum ClothType
{
    Synthetic,
    Tarpaulin,
    Wool,
    Cotton
};
class ClothBackpack : public Backpack
{
private:
    bool waterproof;
    ClothType cloth;

public:
    ~ClothBackpack()
    {
    }
    ClothBackpack()
        : Backpack(), waterproof(false)
    {
    }
    ClothBackpack(string color_,
                  AppointmentType appointment_,
                  bool laptop_comparament_,
                  unsigned volume_,
                  bool waterproof_,
                  ClothType cloth_,
                  const struct Brand &brand_)
        : Backpack(color_, appointment_, laptop_comparament_,
                   volume_, brand_),
          waterproof(waterproof_),
          cloth(cloth_) {}
    std::string display() override
    {
        return "Backpack is: Cloth" + std::to_string(GetVolume());
    };
    virtual bool isLeather() override
    {
        return false;   
    };
    virtual bool isCloth() override
    {
        return true;
    };
};
