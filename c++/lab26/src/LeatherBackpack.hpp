#include "Backpack.hpp"
enum leatherType{
    Smooth,
    Solid,
    Glossy,
    Matt,
};
class LeatherBackpack: public Backpack 
{
private:
    bool has_lining;
    leatherType backpack_leather;
public:
    LeatherBackpack(string color_,
    string appointment_,
    bool laptop_comparament_,
    unsigned volume_,
    bool has_lining_,
    leatherType leather_,
    const Brand &brand_);

    void setLining(bool has_lining_);

    void setLeather(leatherType leather_);

    bool getLining();

    leatherType getLeatherType();

    string ToString()const;
    
    static LeatherBackpack* FillFromString(string str);

};


