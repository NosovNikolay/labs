#include "Backpack.hpp"
enum leatherType{
    Smooth,
    Solid,
    Glossy,
    Matt
};
class LeatherBackpack final: public Backpack
{
private:
    leatherType leather;
    bool has_lining;

public:
    
    LeatherBackpack();

    LeatherBackpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    bool has_lining_,
    leatherType leather_,
    const struct Brand &brand_);

    ~LeatherBackpack();

    string ToString()const override;

    bool FillFromString(string str) override;

    Backpack* Copy()const override;
};

