#ifndef CLOTHBackpack_H
#define CLOTHBackpack_H

#include "Backpack.hpp"
enum ClothType{
    Synthetic,
    Tarpaulin,
    Wool,
    Cotton
};
class ClothBackpack: public Backpack
{
private:
    bool waterproof;
    ClothType cloth;
public:
    ClothBackpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    bool waterproof,
    ClothType cloth,
    const struct Brand &brand_);

    ~ClothBackpack()
    {
        
    }

    bool getWaterproof();

    ClothType getCloth();

    void setWaterproof(bool waterproof);

    void setCloth(ClothType cloth);

    static ClothBackpack* FillFromString(string str);

    string ToString()const;
  
};

#endif
